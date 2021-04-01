
namespace Calculator
{
    partial class CalculatorForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.SignChangeButton = new System.Windows.Forms.Button();
            this.ClearEntryButton = new System.Windows.Forms.Button();
            this.ClearButton = new System.Windows.Forms.Button();
            this.BackSpaceButton = new System.Windows.Forms.Button();
            this.DivisionButton = new System.Windows.Forms.Button();
            this.MultiplicationButton = new System.Windows.Forms.Button();
            this.SubtractionButton = new System.Windows.Forms.Button();
            this.AdditionButton = new System.Windows.Forms.Button();
            this.CommaButton = new System.Windows.Forms.Button();
            this.EqualSignButton = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button0 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel1.ColumnCount = 4;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 96F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 103F));
            this.tableLayoutPanel1.Controls.Add(this.SignChangeButton, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.ClearEntryButton, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.ClearButton, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.BackSpaceButton, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.DivisionButton, 3, 0);
            this.tableLayoutPanel1.Controls.Add(this.MultiplicationButton, 3, 1);
            this.tableLayoutPanel1.Controls.Add(this.SubtractionButton, 3, 2);
            this.tableLayoutPanel1.Controls.Add(this.AdditionButton, 3, 3);
            this.tableLayoutPanel1.Controls.Add(this.CommaButton, 2, 4);
            this.tableLayoutPanel1.Controls.Add(this.EqualSignButton, 3, 4);
            this.tableLayoutPanel1.Controls.Add(this.button1, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.button2, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.button3, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.button4, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.button5, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.button6, 2, 2);
            this.tableLayoutPanel1.Controls.Add(this.button7, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.button8, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.button9, 2, 3);
            this.tableLayoutPanel1.Controls.Add(this.button0, 1, 4);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 47);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 5;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 53.73134F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 46.26866F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 83F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 86F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 77F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(373, 403);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // SignChangeButton
            // 
            this.SignChangeButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.SignChangeButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SignChangeButton.Location = new System.Drawing.Point(3, 328);
            this.SignChangeButton.Name = "SignChangeButton";
            this.SignChangeButton.Size = new System.Drawing.Size(81, 72);
            this.SignChangeButton.TabIndex = 0;
            this.SignChangeButton.Text = "+/-";
            this.SignChangeButton.UseVisualStyleBackColor = false;
            this.SignChangeButton.Click += new System.EventHandler(this.ChangeSignButtonClick);
            // 
            // ClearEntryButton
            // 
            this.ClearEntryButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.ClearEntryButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ClearEntryButton.Location = new System.Drawing.Point(3, 3);
            this.ClearEntryButton.Name = "ClearEntryButton";
            this.ClearEntryButton.Size = new System.Drawing.Size(81, 78);
            this.ClearEntryButton.TabIndex = 1;
            this.ClearEntryButton.Text = "CE";
            this.ClearEntryButton.UseVisualStyleBackColor = false;
            this.ClearEntryButton.Click += new System.EventHandler(this.ClearEntryButtonClick);
            // 
            // ClearButton
            // 
            this.ClearButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.ClearButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ClearButton.Location = new System.Drawing.Point(90, 3);
            this.ClearButton.Name = "ClearButton";
            this.ClearButton.Size = new System.Drawing.Size(81, 78);
            this.ClearButton.TabIndex = 2;
            this.ClearButton.Text = "C";
            this.ClearButton.UseVisualStyleBackColor = false;
            this.ClearButton.Click += new System.EventHandler(this.ClearButtonClick);
            // 
            // BackSpaceButton
            // 
            this.BackSpaceButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.BackSpaceButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.BackSpaceButton.Location = new System.Drawing.Point(177, 3);
            this.BackSpaceButton.Name = "BackSpaceButton";
            this.BackSpaceButton.Size = new System.Drawing.Size(90, 78);
            this.BackSpaceButton.TabIndex = 3;
            this.BackSpaceButton.Text = "<=";
            this.BackSpaceButton.Click += new System.EventHandler(this.BackspaceButtonClick);
            this.BackSpaceButton.UseVisualStyleBackColor = false;
            // 
            // DivisionButton
            // 
            this.DivisionButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.DivisionButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.DivisionButton.Location = new System.Drawing.Point(273, 3);
            this.DivisionButton.Name = "DivisionButton";
            this.DivisionButton.Size = new System.Drawing.Size(97, 78);
            this.DivisionButton.TabIndex = 4;
            this.DivisionButton.Text = "/";
            this.DivisionButton.Click += new System.EventHandler(this.OperationButtonClick);
            this.DivisionButton.UseVisualStyleBackColor = false;
            // 
            // MultiplicationButton
            // 
            this.MultiplicationButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.MultiplicationButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.MultiplicationButton.Location = new System.Drawing.Point(273, 87);
            this.MultiplicationButton.Name = "MultiplicationButton";
            this.MultiplicationButton.Size = new System.Drawing.Size(97, 66);
            this.MultiplicationButton.TabIndex = 5;
            this.MultiplicationButton.Click += new System.EventHandler(this.OperationButtonClick);
            this.MultiplicationButton.Text = "*";
            this.MultiplicationButton.UseVisualStyleBackColor = false;
            // 
            // SubtractionButton
            // 
            this.SubtractionButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.SubtractionButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SubtractionButton.Location = new System.Drawing.Point(273, 159);
            this.SubtractionButton.Name = "SubtractionButton";
            this.SubtractionButton.Size = new System.Drawing.Size(97, 77);
            this.SubtractionButton.TabIndex = 6;
            this.SubtractionButton.Text = "-";
            this.SubtractionButton.Click += new System.EventHandler(this.OperationButtonClick);
            this.SubtractionButton.UseVisualStyleBackColor = false;
            // 
            // AdditionButton
            // 
            this.AdditionButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.AdditionButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.AdditionButton.Location = new System.Drawing.Point(273, 242);
            this.AdditionButton.Name = "AdditionButton";
            this.AdditionButton.Size = new System.Drawing.Size(97, 80);
            this.AdditionButton.TabIndex = 7;
            this.AdditionButton.Text = "+";
            this.AdditionButton.Click += new System.EventHandler(this.OperationButtonClick);
            this.AdditionButton.UseVisualStyleBackColor = false;
            // 
            // CommaButton
            // 
            this.CommaButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.CommaButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.CommaButton.Location = new System.Drawing.Point(177, 328);
            this.CommaButton.Name = "CommaButton";
            this.CommaButton.Size = new System.Drawing.Size(90, 72);
            this.CommaButton.TabIndex = 8;
            this.CommaButton.Text = ",";
            this.CommaButton.Click += new System.EventHandler(this.DecimalSeparatorButtonClick);
            this.CommaButton.UseVisualStyleBackColor = false;
            // 
            // EqualSignButton
            // 
            this.EqualSignButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.EqualSignButton.Dock = System.Windows.Forms.DockStyle.Fill;
            this.EqualSignButton.Location = new System.Drawing.Point(273, 328);
            this.EqualSignButton.Name = "EqualSignButton";
            this.EqualSignButton.Size = new System.Drawing.Size(97, 72);
            this.EqualSignButton.TabIndex = 9;
            this.EqualSignButton.Text = "=";
            this.EqualSignButton.Click += new System.EventHandler(this.EqualSignButtonClick);
            this.EqualSignButton.UseVisualStyleBackColor = false;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button1.Location = new System.Drawing.Point(3, 87);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(81, 66);
            this.button1.TabIndex = 10;
            this.button1.Text = "1";
            this.button1.Click += new System.EventHandler(this.DigitButtonClick);
            this.button1.UseVisualStyleBackColor = false;
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button2.Location = new System.Drawing.Point(90, 87);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(81, 66);
            this.button2.TabIndex = 11;
            this.button2.Text = "2";
            this.button2.Click += new System.EventHandler(this.DigitButtonClick);
            this.button2.UseVisualStyleBackColor = false;
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button3.Location = new System.Drawing.Point(177, 87);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(90, 66);
            this.button3.TabIndex = 12;
            this.button3.Text = "3";
            this.button3.Click += new System.EventHandler(this.DigitButtonClick);
            this.button3.UseVisualStyleBackColor = false;
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button4.Location = new System.Drawing.Point(3, 159);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(81, 77);
            this.button4.TabIndex = 13;
            this.button4.Text = "4";
            this.button4.Click += new System.EventHandler(this.DigitButtonClick);
            this.button4.UseVisualStyleBackColor = false;
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button5.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button5.Location = new System.Drawing.Point(90, 159);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(81, 77);
            this.button5.TabIndex = 14;
            this.button5.Text = "5";
            this.button5.Click += new System.EventHandler(this.DigitButtonClick);
            this.button5.UseVisualStyleBackColor = false;
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button6.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button6.Location = new System.Drawing.Point(177, 159);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(90, 77);
            this.button6.TabIndex = 15;
            this.button6.Text = "6";
            this.button6.Click += new System.EventHandler(this.DigitButtonClick);
            this.button6.UseVisualStyleBackColor = false;
            // 
            // button7
            // 
            this.button7.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button7.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button7.Location = new System.Drawing.Point(3, 242);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(81, 80);
            this.button7.TabIndex = 16;
            this.button7.Text = "7";
            this.button7.Click += new System.EventHandler(this.DigitButtonClick);
            this.button7.UseVisualStyleBackColor = false;
            // 
            // button8
            // 
            this.button8.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button8.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button8.Location = new System.Drawing.Point(90, 242);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(81, 80);
            this.button8.TabIndex = 17;
            this.button8.Text = "8";
            this.button8.Click += new System.EventHandler(this.DigitButtonClick);
            this.button8.UseVisualStyleBackColor = false;
            // 
            // button9
            // 
            this.button9.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button9.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button9.Location = new System.Drawing.Point(177, 242);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(90, 80);
            this.button9.TabIndex = 18;
            this.button9.Text = "9";
            this.button9.Click += new System.EventHandler(this.DigitButtonClick);
            this.button9.UseVisualStyleBackColor = false;
            // 
            // button0
            // 
            this.button0.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.button0.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button0.Location = new System.Drawing.Point(90, 328);
            this.button0.Name = "button0";
            this.button0.Size = new System.Drawing.Size(81, 72);
            this.button0.TabIndex = 19;
            this.button0.Text = "0";
            this.button0.Click += new System.EventHandler(this.DigitButtonClick);
            this.button0.UseVisualStyleBackColor = false;
            // 
            // textBox1
            // 
            this.textBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBox1.BackColor = System.Drawing.SystemColors.Info;
            this.textBox1.Location = new System.Drawing.Point(0, 13);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(373, 31);
            this.textBox1.TabIndex = 1;
            this.textBox1.Text = "0";
            this.textBox1.Enter += new System.EventHandler(this.TextBoxFocusEnter);
            // 
            // CalculatorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "CalculatorForm";
            this.Text = "Calculator";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Button SignChangeButton;
        private System.Windows.Forms.Button ClearEntryButton;
        private System.Windows.Forms.Button ClearButton;
        private System.Windows.Forms.Button BackSpaceButton;
        private System.Windows.Forms.Button DivisionButton;
        private System.Windows.Forms.Button MultiplicationButton;
        private System.Windows.Forms.Button SubtractionButton;
        private System.Windows.Forms.Button AdditionButton;
        private System.Windows.Forms.Button CommaButton;
        private System.Windows.Forms.Button EqualSignButton;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button0;
        private System.Windows.Forms.TextBox textBox1;
    }
}

