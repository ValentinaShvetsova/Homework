using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProgressBar
{
    public partial class ButtonAndProgressForm : Form
    {
        public ButtonAndProgressForm()
        {
            InitializeComponent();
        }

        private void CloseButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void IndicatorButton_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void progressBar_Click(object sender, EventArgs e)
        {
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (progressBar.Maximum - 1 < progressBar.Value)
            {
                CloseButton.Visible = true;
                timer1.Enabled = false;
            }

            progressBar.PerformStep();
        }

        private void ButtonAndProgressBar_Load(object sender, EventArgs e)
        {
            timer1.Interval = 500;
            timer1.Tick += new EventHandler(timer1_Tick);
            progressBar.Step = 1;
            progressBar.Minimum = 0;
            progressBar.Maximum = 100;
        }
    }
}
