using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace DHT11_GETTER
{
    class SerialReader
        : IDisposable
    {
        public SerialReader(string port, int baudRate)
        {
            arduinoPort = new SerialPort(port);
            arduinoPort.BaudRate = 9600;
            arduinoPort.DataReceived += arduinoPort_DataReceived;
            arduinoPort.Open();
            
        }
        void arduinoPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort port = sender as SerialPort;
            string data = port.ReadLine();
            readData = translator.serializeJson(data);
        }
        public void Dispose()
        {
            arduinoPort.Close();
            arduinoPort.Dispose();
        }
        public SerialPort arduinoPort;

        private SensorData readData = new SensorData();

        public SensorData dataReaded
        {
            get { return readData; }
            set { readData = value; }
        }

        JsonTranslator translator = new JsonTranslator();
    }
}
