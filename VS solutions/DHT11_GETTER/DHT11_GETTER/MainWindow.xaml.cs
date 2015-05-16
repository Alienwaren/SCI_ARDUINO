using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Timers;
using System.Windows.Threading;
using System.Net;
namespace DHT11_GETTER
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            timerRefreshUi.Interval = new TimeSpan(0, 0, 0, 0, 500);
            timerRefreshUi.Tick += timerRefreshUi_Tick;
            timerRefreshUi.Start();
        }

        void timerRefreshUi_Tick(object sender, EventArgs e)
        {
            if (reader.dataReaded != null)
            {
                _temperatureValue.Text = reader.dataReaded.temperatureValue.ToString();
                _humidityValue.Text = reader.dataReaded.humidityTemperature.ToString();
                WebRequest webRequest = WebRequest.Create("http://api.thingspeak.com/update?key="+apiKey+"&field1="+_temperatureValue.Text+"&field2="+_humidityValue.Text);
                webRequest.Method = "GET";
                WebResponse webResp = webRequest.GetResponse();
            }

        }

        protected override void OnClosed(EventArgs e)
        {
            base.OnClosed(e);
           reader.Dispose();
        }
        SerialReader reader = new SerialReader("COM6", 9600); ////TODO: MOVE PORT CONF TO XML

        DispatcherTimer timerRefreshUi = new DispatcherTimer();

        private string apiKey = "DOXOWDS1596CT2J7"; //tu wstawcie swój klucz api
    }
}
