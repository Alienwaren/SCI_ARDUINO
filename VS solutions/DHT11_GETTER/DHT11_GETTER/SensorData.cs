using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DHT11_GETTER
{
    public class SensorData
    {
        public SensorData()
        {

        }
        public SensorData(int temperature, int humidity)
        {
            this.temperature = temperature;
            this.humidity = humidity;
        }
        private int temperature;

        public int temperatureValue
        {
            get { return temperature; }
            set { temperature = value; }
        }
        private int humidity;

        public int humidityTemperature
        {
            get { return humidity; }
            set { humidity = value; }
        }
           
    }
}
