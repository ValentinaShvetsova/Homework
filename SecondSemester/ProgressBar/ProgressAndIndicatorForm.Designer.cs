
namespace ProgressBar
{
    partial class ButtonAndProgressForm
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
            this.components = new System.ComponentModel.Container();
            this.IndicatorButton = new System.Windows.Forms.Button();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.CloseButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // IndicatorButton
            // 
            this.IndicatorButton.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.IndicatorButton.Location = new System.Drawing.Point(109, 113);
            this.IndicatorButton.Name = "IndicatorButton";
            this.IndicatorButton.Size = new System.Drawing.Size(128, 45);
            this.IndicatorButton.TabIndex = 0;
            this.IndicatorButton.Text = "Click on me!";
            this.IndicatorButton.UseVisualStyleBackColor = false;
            this.IndicatorButton.Click += new System.EventHandler(this.IndicatorButton_Click);
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(109, 232);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(507, 47);
            this.progressBar.TabIndex = 1;
            this.progressBar.Click += new System.EventHandler(this.progressBar_Click);
            // 
            // timer1
            // 
            this.timer1.Interval = 500;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // CloseButton
            // 
            this.CloseButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(128)))));
            this.CloseButton.Location = new System.Drawing.Point(496, 113);
            this.CloseButton.Name = "CloseButton";
            this.CloseButton.Size = new System.Drawing.Size(120, 45);
            this.CloseButton.TabIndex = 2;
            this.CloseButton.Text = "Close";
            this.CloseButton.UseVisualStyleBackColor = false;
            this.CloseButton.Visible = false;
            this.CloseButton.Click += new System.EventHandler(this.CloseButton_Click);
            // 
            // ButtonAndProgressForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Info;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.CloseButton);
            this.Controls.Add(this.progressBar);
            this.Controls.Add(this.IndicatorButton);
            this.Name = "ButtonAndProgressForm";
            this.Text = "ButtonAndProgress";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button IndicatorButton;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button CloseButton;
    }
}

