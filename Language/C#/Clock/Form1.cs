using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clock
{
    public partial class Clock : Form
    {
        private double PI = Math.PI;

        public Clock()
        {
            InitializeComponent();
        }

        private Pen giveMePen(Color x, int width)
        {
            return new Pen(x, width);
        }

        // 圆所在矩形的左上角点坐标x, y; 直径dia; which: 0(北京时间), 1(世界统一时间)
        private void DrawClock(Graphics g, int x, int y, int dia, int hour, int minu, int sec, bool which)
        {
            // 绘制表盘
            g.DrawEllipse(giveMePen(Color.Black, 1), x, y, dia, dia);

            // 得到秒针、分针、时针终点位置
            int rad = dia / 2;
            Point center = new Point(x + rad, y + rad);
            Point secPoint = new Point((int)(center.X + (Math.Sin(sec * PI / 30) * (rad / 10 * 9))), 
                                       (int)(center.Y - (Math.Cos(sec * PI / 30) * (rad / 10 * 9))));
            Point minPoint = new Point((int)(center.X + (Math.Sin(minu * PI / 30) * (rad / 10 * 7))), 
                                       (int)(center.Y - (Math.Cos(minu * PI / 30) * (rad / 10 * 7))));
            Point hourPoint = new Point((int)(center.X + (Math.Sin((hour + (double)minu / 60) * PI / 12) * (rad / 10 * 5))), 
                                        (int)(center.Y - (Math.Cos((hour + (double)minu / 60) * PI / 12) * (rad / 10 * 5))));

            // 显示时钟表盘
            Graphics ng = this.CreateGraphics();
            ng.TranslateTransform(center.X, center.Y);
            for (int i = 0; i < 60; ++i)
            {
                if (i % 5 == 0)
                {
                    ng.FillRectangle(new SolidBrush(Color.Gray), -1, 2 - rad, 2, rad / 15);
                }
                else
                {
                    ng.FillRectangle(new SolidBrush(Color.Gray), 0, 2 - rad, 1, rad / 18);
                }
                ng.RotateTransform(6); 
            }

            // 显示时钟指针
            g.DrawLine(giveMePen(Color.Red, 1), center, secPoint);
            g.DrawLine(giveMePen(Color.Black, 2), center, minPoint);
            g.DrawLine(giveMePen(Color.Black, 3), center, hourPoint);

            // 显示时区、时间字符串 which: 0(北京时间), 1(世界统一时间)
            if (which)
            {
                int len = rad / 10;
                UTC.SetBounds(center.X - len, center.Y - rad - 2 * len, len, 2 * len);
                UTCDate.SetBounds(center.X + 2 * rad, center.Y - rad / 3, rad, 2 * rad);
                UTCDate.Text = hour.ToString().PadLeft(2, '0') + ":" + minu.ToString().PadLeft(2, '0') + ":" + sec.ToString().PadLeft(2, '0');
                UTCDate.Font = new Font("隶书", rad / 2, FontStyle.Regular);
            }
            else
            {
                int len = rad / 10;
                BeiJing.SetBounds(center.X - 3 * len, center.Y - rad - 2 * len, len, 2 * len);
                BJDate.SetBounds(center.X + 2 * rad, center.Y - rad / 3, rad, 2 * rad);
                BJDate.Text = hour.ToString().PadLeft(2, '0') + ":" + minu.ToString().PadLeft(2, '0') + ":" + sec.ToString().PadLeft(2, '0');
                BJDate.Font = new Font("隶书", rad / 2, FontStyle.Regular);
            }

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            // 获得窗口矩形
            Rectangle rect = this.ClientRectangle;
            int width = rect.Width, hight = rect.Height;
            // 使用白色清空画面
            g.Clear(Color.White);

            // 绘制北京时间时钟
            int hour = DateTime.Now.Hour;
            int minu = DateTime.Now.Minute;
            int sec = DateTime.Now.Second;
            DrawClock(g, width / 8, hight / 10, hight / 3, hour, minu, sec, false);

            // 绘制UTC时间时钟
            hour = DateTime.UtcNow.Hour;
            minu = DateTime.UtcNow.Minute;
            sec = DateTime.UtcNow.Second;
            DrawClock(g, width / 8, hight / 2, hight / 3, hour, minu, sec, true);
        }
    }
}
