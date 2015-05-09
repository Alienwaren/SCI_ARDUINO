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
            }
        }

        protected override void OnClosed(EventArgs e)
        {
            base.OnClosed(e);
            reader.Dispose();
        }
        SerialReader reader = new SerialReader("COM5", 9600); ////TODO: MOVE PORT CONF TO XML

        DispatcherTimer timerRefreshUi = new DispatcherTimer();
    }
}
