using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.IO;
using System.Windows;
namespace DHT11_GETTER
{
    public class JsonTranslator
    {
        public JsonTranslator()
        {

        }
        public SensorData serializeJson(string jsonString)
        {
            SensorData data = new SensorData();
            int valueNumber = 0;
            JsonTextReader reader = new JsonTextReader(new StringReader(jsonString));
            while(reader.Read())
            {
                if (reader.TokenType == JsonToken.Integer && valueNumber == 0)
                {
                    data.temperatureValue = int.Parse(reader.Value.ToString());
                    valueNumber++;
                }else if(reader.TokenType == JsonToken.Integer && valueNumber == 1)
                {
                    data.humidityTemperature = int.Parse(reader.Value.ToString());
                }
            }
            return data;
        }
    }
}
