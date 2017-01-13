namespace Clock
{
    partial class Clock
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.BeiJing = new System.Windows.Forms.Label();
            this.UTC = new System.Windows.Forms.Label();
            this.BJDate = new System.Windows.Forms.Label();
            this.UTCDate = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // BeiJing
            // 
            this.BeiJing.AutoSize = true;
            this.BeiJing.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.BeiJing.Location = new System.Drawing.Point(3, 9);
            this.BeiJing.Name = "BeiJing";
            this.BeiJing.Size = new System.Drawing.Size(53, 12);
            this.BeiJing.TabIndex = 0;
            this.BeiJing.Text = "Bei Jing";
            // 
            // UTC
            // 
            this.UTC.AutoSize = true;
            this.UTC.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.UTC.Location = new System.Drawing.Point(12, 163);
            this.UTC.Name = "UTC";
            this.UTC.Size = new System.Drawing.Size(23, 12);
            this.UTC.TabIndex = 1;
            this.UTC.Text = "UTC";
            // 
            // BJDate
            // 
            this.BJDate.AutoSize = true;
            this.BJDate.Location = new System.Drawing.Point(272, 84);
            this.BJDate.Name = "BJDate";
            this.BJDate.Size = new System.Drawing.Size(41, 12);
            this.BJDate.TabIndex = 2;
            this.BJDate.Text = "label1";
            // 
            // UTCDate
            // 
            this.UTCDate.AutoSize = true;
            this.UTCDate.Location = new System.Drawing.Point(274, 217);
            this.UTCDate.Name = "UTCDate";
            this.UTCDate.Size = new System.Drawing.Size(41, 12);
            this.UTCDate.TabIndex = 3;
            this.UTCDate.Text = "label1";
            // 
            // Clock
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(637, 379);
            this.Controls.Add(this.UTCDate);
            this.Controls.Add(this.BJDate);
            this.Controls.Add(this.BeiJing);
            this.Controls.Add(this.UTC);
            this.Name = "Clock";
            this.Text = "Time Machine";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label BeiJing;
        private System.Windows.Forms.Label UTC;
        private System.Windows.Forms.Label BJDate;
        private System.Windows.Forms.Label UTCDate;
    }
}

