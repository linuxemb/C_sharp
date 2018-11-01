namespace Elephant
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.LIovd = new System.Windows.Forms.Button();
            this.Lucinda = new System.Windows.Forms.Button();
            this.Swap = new System.Windows.Forms.Button();
            this.bad_swap = new System.Windows.Forms.Button();
            this.bigestEar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // LIovd
            // 
            this.LIovd.Location = new System.Drawing.Point(82, 39);
            this.LIovd.Name = "LIovd";
            this.LIovd.Size = new System.Drawing.Size(75, 23);
            this.LIovd.TabIndex = 0;
            this.LIovd.Text = "LIovd";
            this.LIovd.UseVisualStyleBackColor = true;
            this.LIovd.Click += new System.EventHandler(this.LIovd_Click);
            // 
            // Lucinda
            // 
            this.Lucinda.Location = new System.Drawing.Point(82, 68);
            this.Lucinda.Name = "Lucinda";
            this.Lucinda.Size = new System.Drawing.Size(75, 23);
            this.Lucinda.TabIndex = 1;
            this.Lucinda.Text = "Lucinda";
            this.Lucinda.UseVisualStyleBackColor = true;
            this.Lucinda.Click += new System.EventHandler(this.Lucinda_Click);
            // 
            // Swap
            // 
            this.Swap.Location = new System.Drawing.Point(82, 97);
            this.Swap.Name = "Swap";
            this.Swap.Size = new System.Drawing.Size(75, 23);
            this.Swap.TabIndex = 2;
            this.Swap.Text = "Swap";
            this.Swap.UseVisualStyleBackColor = true;
            this.Swap.Click += new System.EventHandler(this.Swap_Click);
            // 
            // bad_swap
            // 
            this.bad_swap.Location = new System.Drawing.Point(82, 141);
            this.bad_swap.Name = "bad_swap";
            this.bad_swap.Size = new System.Drawing.Size(75, 23);
            this.bad_swap.TabIndex = 3;
            this.bad_swap.Text = "bad_swap";
            this.bad_swap.UseVisualStyleBackColor = true;
            this.bad_swap.Click += new System.EventHandler(this.button1_Click);
            // 
            // bigestEar
            // 
            this.bigestEar.Location = new System.Drawing.Point(82, 191);
            this.bigestEar.Name = "bigestEar";
            this.bigestEar.Size = new System.Drawing.Size(75, 23);
            this.bigestEar.TabIndex = 4;
            this.bigestEar.Text = "bigestEar";
            this.bigestEar.UseVisualStyleBackColor = true;
            this.bigestEar.Click += new System.EventHandler(this.bigestEar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.bigestEar);
            this.Controls.Add(this.bad_swap);
            this.Controls.Add(this.Swap);
            this.Controls.Add(this.Lucinda);
            this.Controls.Add(this.LIovd);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button LIovd;
        private System.Windows.Forms.Button Lucinda;
        private System.Windows.Forms.Button Swap;
        private System.Windows.Forms.Button bad_swap;
        private System.Windows.Forms.Button bigestEar;
    }
}

