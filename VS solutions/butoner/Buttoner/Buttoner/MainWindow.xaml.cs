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
using Sharpduino;
using System.Threading;
namespace Buttoner
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {

        }

        private void _dropDownPins_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox cmb = sender as ComboBox; //bierzemy combobox
            ComboBoxItem value = cmb.SelectedItem as ComboBoxItem; //potem jego item
            string valueString = value.Content as string; ///a na końcu wartość
            actualPin = int.Parse(valueString);  //a teraz int to string
        }
        private void _toggleButton_Click(object sender, RoutedEventArgs e)
        {
            switch (actualPin)
            {
                case 1:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D1_TX, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D1_TX, true);
                    break;
                case 2:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D2, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D2, true);
                    break;
                case 3:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D3_PWM, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D3_PWM, true);
                    break;
                case 4:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D4, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D4, true);

                    break;
                case 5:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D5_PWM, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D5_PWM, true);

                    break;
                case 6:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D6_PWM, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D6_PWM, true);

                    break;
                case 7:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D7, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D7, true);

                    break;
                case 8:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D8, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D8, true);

                    break;
                case 9:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D9_PWM, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D9_PWM, true);

                    break;
                case 10:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D10_PWM, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D10_PWM, true);

                    break;
                case 11:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D11_PWM, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D11_PWM, true);

                    break;
                case 12:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D12, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D12, true);

                    break;
                case 13:
                    ardus.SetPinMode(Sharpduino.Constants.ArduinoUnoPins.D13, Sharpduino.Constants.PinModes.Output);
                    ardus.SetDO(Sharpduino.Constants.ArduinoUnoPins.D13, true);
                    break;
                default:
                    break;
            }
        }
        /// <summary>
        /// Obiekt arduino
        /// </summary>
        ArduinoUno ardus = new ArduinoUno("COM4");
        /// <summary>
        /// Aktualny pin
        /// </summary>
        int actualPin = 13;

       

       
        
    }
}
