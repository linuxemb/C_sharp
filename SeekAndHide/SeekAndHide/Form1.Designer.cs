﻿namespace SeekAndHide
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
            this.description = new System.Windows.Forms.TextBox();
            this.goHere = new System.Windows.Forms.Button();
            this.goThroughDoor = new System.Windows.Forms.Button();
            this.exits = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // description
            // 
            this.description.Location = new System.Drawing.Point(78, 52);
            this.description.Multiline = true;
            this.description.Name = "description";
            this.description.Size = new System.Drawing.Size(346, 154);
            this.description.TabIndex = 0;
            this.description.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // goHere
            // 
            this.goHere.Location = new System.Drawing.Point(89, 236);
            this.goHere.Name = "goHere";
            this.goHere.Size = new System.Drawing.Size(75, 23);
            this.goHere.TabIndex = 1;
            this.goHere.Text = "Gohere";
            this.goHere.UseVisualStyleBackColor = true;
            this.goHere.Click += new System.EventHandler(this.goHere_Click);
            // 
            // goThroughDoor
            // 
            this.goThroughDoor.Location = new System.Drawing.Point(162, 278);
            this.goThroughDoor.Name = "goThroughDoor";
            this.goThroughDoor.Size = new System.Drawing.Size(148, 26);
            this.goThroughDoor.TabIndex = 3;
            this.goThroughDoor.Text = "GoThroughTheDoor";
            this.goThroughDoor.UseVisualStyleBackColor = true;
            this.goThroughDoor.Click += new System.EventHandler(this.goThroughDoor_Click);
            // 
            // exits
            // 
            this.exits.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.exits.FormattingEnabled = true;
            this.exits.Location = new System.Drawing.Point(309, 236);
            this.exits.Name = "exits";
            this.exits.Size = new System.Drawing.Size(98, 21);
            this.exits.TabIndex = 4;
            this.exits.SelectedIndexChanged += new System.EventHandler(this.exits_SelectedIndexChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(487, 316);
            this.Controls.Add(this.exits);
            this.Controls.Add(this.goThroughDoor);
            this.Controls.Add(this.goHere);
            this.Controls.Add(this.description);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox description;
        private System.Windows.Forms.Button goHere;
        private System.Windows.Forms.Button goThroughDoor;
        private System.Windows.Forms.ComboBox exits;
    }
}

