using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class CalculatorForm : Form
    {
        public CalculatorForm()
        {
            InitializeComponent();
        }

        private readonly SuperCalculator calculator = new SuperCalculator();

        private const string initialEntry = "0";
        private const string errorMessage = "Error";
        private string Entry
        {
            get => textBox1.Text;
            set => textBox1.Text = value;
        }

        private bool isResultShown;
        private bool operationSelected;
        private bool afterEqualSign;

        /// <summary>
        /// Moves focus from the text box.
        /// </summary>
        private void TextBoxFocusEnter(object sender, EventArgs e) => EqualSignButton.Focus();

        /// <summary>
        /// Handles a click on a numeric button.
        /// </summary>
        private void DigitButtonClick(object sender, EventArgs e)
        {
            var button = (Button)sender;
            var shouldCreateNewNumber = Entry == initialEntry || isResultShown;
            Entry = shouldCreateNewNumber ? button.Text : Entry + button.Text;
            isResultShown = false;
        }

        /// <summary>
        /// Handles a click on the change sign button.
        /// </summary>
        private void ChangeSignButtonClick(object sender, EventArgs e)
        {
            if (Entry == initialEntry || Entry == errorMessage)
                return;

            Entry = (Entry[0] == '-') ? Entry.Remove(0, 1) : Entry.Insert(0, "-");

            isResultShown = false;
        }

        /// <summary>
        /// Handles a click the decimal separator button.
        /// </summary>
        private void DecimalSeparatorButtonClick(object sender, EventArgs e)
        {
            if (isResultShown)
            {
                Entry = initialEntry;
                isResultShown = false;
            }

            if (Entry.Contains(','))
                return;

            Entry = Entry.Insert(Entry.Length, ",");
        }

        /// <summary>
        /// Handles a click the Clear Entry button.
        /// </summary>
        private void ClearEntryButtonClick(object sender, EventArgs e) => ClearEntry();

        /// <summary>
        /// Handles a click the Clear button.
        /// </summary>
        private void ClearButtonClick(object sender, EventArgs e)
        {
            ClearEntry();
            calculator.Clear();
            operationSelected = false;
            afterEqualSign = false;
        }

        private void ClearEntry()
        {
            Entry = initialEntry;
            isResultShown = false;
        }

        /// <summary>
        /// Handles a click the Backspace button.
        /// </summary>
        private void BackspaceButtonClick(object sender, EventArgs e)
        {
            if (isResultShown)
                return;

            var length = Entry.Length;
            var makeInitial = length == 1 || (Entry[0] == '-' && length == 2);
            Entry = makeInitial ? initialEntry : Entry.Remove(length - 1);
        }

        /// <summary>
        /// Handles a click on the operation button.
        /// </summary>
        private void OperationButtonClick(object sender, EventArgs e)
        {
            if (Entry == errorMessage)
                return;

            if (!isResultShown)
            {
                if (afterEqualSign)
                {
                    calculator.Clear();
                    operationSelected = false;
                }

                calculator.AddNumber(Convert.ToDouble(Entry));
                if (operationSelected)
                {
                    PrintResult();
                }
            }

            var sign = ((Button)sender).Text;
            var operation = GetOperation(sign);
            calculator.AddOperation(operation);

            isResultShown = true;
            operationSelected = true;
            afterEqualSign = false;
        }

        private Operation GetOperation(string sign) =>
            sign switch
            {
                "+" => Operation.Addition,
                "-" => Operation.Subtraction,
                "×" => Operation.Multiplication,
                "÷" => Operation.Division,
                _ => throw new InvalidOperationSignException()
            };

        /// <summary>
        /// Handles a click the equal sign button.
        /// </summary>
        private void EqualSignButtonClick(object sender, EventArgs e)
        {
            if (!isResultShown || !afterEqualSign)
            {
                calculator.AddNumber(Convert.ToDouble(Entry));
            }

            if (operationSelected)
            {
                PrintResult();
            }

            isResultShown = true;
            afterEqualSign = true;
        }

        private void PrintResult()
        {
            try
            {
                Entry = calculator.Calculate().ToString();
            }
            catch (DivideByZeroException)
            {
                Entry = errorMessage;
                calculator.Clear();
                operationSelected = false;
            }
        }
    }
}
