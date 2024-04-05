namespace WindowsFormsApp2
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.dosyaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yeniToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dosyaAçToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dosyaKaydetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.çıkışToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.biçimToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yazıTipiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.renkToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yazıRengiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zeminRengiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ayarlarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kopyalaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yapıştırToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.openFileDialog2 = new System.Windows.Forms.OpenFileDialog();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.yeniToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.açToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.kaydetToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.yazdırToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.kesToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.kopyalaToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.yapıştırToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.printDocument1 = new System.Drawing.Printing.PrintDocument();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.kesToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.kopyalaToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.yapıştırToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.yeniCProjesiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yeniCProjesiToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.yeniCProjesiToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dosyaToolStripMenuItem,
            this.biçimToolStripMenuItem,
            this.ayarlarToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 30);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // dosyaToolStripMenuItem
            // 
            this.dosyaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.yeniToolStripMenuItem,
            this.dosyaAçToolStripMenuItem,
            this.dosyaKaydetToolStripMenuItem,
            this.çıkışToolStripMenuItem});
            this.dosyaToolStripMenuItem.Name = "dosyaToolStripMenuItem";
            this.dosyaToolStripMenuItem.Size = new System.Drawing.Size(64, 26);
            this.dosyaToolStripMenuItem.Text = "Dosya";
            this.dosyaToolStripMenuItem.Click += new System.EventHandler(this.dosyaToolStripMenuItem_Click);
            // 
            // yeniToolStripMenuItem
            // 
            this.yeniToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.yeniCProjesiToolStripMenuItem,
            this.yeniCProjesiToolStripMenuItem1,
            this.yeniCProjesiToolStripMenuItem2});
            this.yeniToolStripMenuItem.Name = "yeniToolStripMenuItem";
            this.yeniToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.yeniToolStripMenuItem.Text = "Yeni";
            this.yeniToolStripMenuItem.Click += new System.EventHandler(this.yeniToolStripMenuItem_Click);
            // 
            // dosyaAçToolStripMenuItem
            // 
            this.dosyaAçToolStripMenuItem.Name = "dosyaAçToolStripMenuItem";
            this.dosyaAçToolStripMenuItem.Size = new System.Drawing.Size(183, 26);
            this.dosyaAçToolStripMenuItem.Text = "Dosya Aç";
            this.dosyaAçToolStripMenuItem.Click += new System.EventHandler(this.dosyaAçToolStripMenuItem_Click);
            // 
            // dosyaKaydetToolStripMenuItem
            // 
            this.dosyaKaydetToolStripMenuItem.Name = "dosyaKaydetToolStripMenuItem";
            this.dosyaKaydetToolStripMenuItem.Size = new System.Drawing.Size(183, 26);
            this.dosyaKaydetToolStripMenuItem.Text = "Dosya Kaydet";
            this.dosyaKaydetToolStripMenuItem.Click += new System.EventHandler(this.dosyaKaydetToolStripMenuItem_Click);
            // 
            // çıkışToolStripMenuItem
            // 
            this.çıkışToolStripMenuItem.Name = "çıkışToolStripMenuItem";
            this.çıkışToolStripMenuItem.Size = new System.Drawing.Size(183, 26);
            this.çıkışToolStripMenuItem.Text = "Çıkış";
            this.çıkışToolStripMenuItem.Click += new System.EventHandler(this.çıkışToolStripMenuItem_Click);
            // 
            // biçimToolStripMenuItem
            // 
            this.biçimToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.yazıTipiToolStripMenuItem,
            this.renkToolStripMenuItem});
            this.biçimToolStripMenuItem.Name = "biçimToolStripMenuItem";
            this.biçimToolStripMenuItem.Size = new System.Drawing.Size(60, 24);
            this.biçimToolStripMenuItem.Text = "Biçim";
            this.biçimToolStripMenuItem.Click += new System.EventHandler(this.biçimToolStripMenuItem_Click);
            // 
            // yazıTipiToolStripMenuItem
            // 
            this.yazıTipiToolStripMenuItem.Name = "yazıTipiToolStripMenuItem";
            this.yazıTipiToolStripMenuItem.Size = new System.Drawing.Size(147, 26);
            this.yazıTipiToolStripMenuItem.Text = "Yazı Tipi";
            this.yazıTipiToolStripMenuItem.Click += new System.EventHandler(this.yazıTipiToolStripMenuItem_Click);
            // 
            // renkToolStripMenuItem
            // 
            this.renkToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.yazıRengiToolStripMenuItem,
            this.zeminRengiToolStripMenuItem});
            this.renkToolStripMenuItem.Name = "renkToolStripMenuItem";
            this.renkToolStripMenuItem.Size = new System.Drawing.Size(147, 26);
            this.renkToolStripMenuItem.Text = "Renk";
            this.renkToolStripMenuItem.Click += new System.EventHandler(this.renkToolStripMenuItem_Click);
            // 
            // yazıRengiToolStripMenuItem
            // 
            this.yazıRengiToolStripMenuItem.Name = "yazıRengiToolStripMenuItem";
            this.yazıRengiToolStripMenuItem.Size = new System.Drawing.Size(172, 26);
            this.yazıRengiToolStripMenuItem.Text = "Yazı rengi";
            this.yazıRengiToolStripMenuItem.Click += new System.EventHandler(this.yazıRengiToolStripMenuItem_Click);
            // 
            // zeminRengiToolStripMenuItem
            // 
            this.zeminRengiToolStripMenuItem.Name = "zeminRengiToolStripMenuItem";
            this.zeminRengiToolStripMenuItem.Size = new System.Drawing.Size(172, 26);
            this.zeminRengiToolStripMenuItem.Text = "Zemin rengi";
            this.zeminRengiToolStripMenuItem.Click += new System.EventHandler(this.zeminRengiToolStripMenuItem_Click);
            // 
            // ayarlarToolStripMenuItem
            // 
            this.ayarlarToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kesToolStripMenuItem,
            this.kopyalaToolStripMenuItem,
            this.yapıştırToolStripMenuItem});
            this.ayarlarToolStripMenuItem.Name = "ayarlarToolStripMenuItem";
            this.ayarlarToolStripMenuItem.Size = new System.Drawing.Size(98, 26);
            this.ayarlarToolStripMenuItem.Text = "Düzenleme";
            // 
            // kesToolStripMenuItem
            // 
            this.kesToolStripMenuItem.Name = "kesToolStripMenuItem";
            this.kesToolStripMenuItem.Size = new System.Drawing.Size(146, 26);
            this.kesToolStripMenuItem.Text = "Kes";
            this.kesToolStripMenuItem.Click += new System.EventHandler(this.kesToolStripMenuItem_Click);
            // 
            // kopyalaToolStripMenuItem
            // 
            this.kopyalaToolStripMenuItem.Name = "kopyalaToolStripMenuItem";
            this.kopyalaToolStripMenuItem.Size = new System.Drawing.Size(146, 26);
            this.kopyalaToolStripMenuItem.Text = "Kopyala";
            this.kopyalaToolStripMenuItem.Click += new System.EventHandler(this.kopyalaToolStripMenuItem_Click);
            // 
            // yapıştırToolStripMenuItem
            // 
            this.yapıştırToolStripMenuItem.Name = "yapıştırToolStripMenuItem";
            this.yapıştırToolStripMenuItem.Size = new System.Drawing.Size(146, 26);
            this.yapıştırToolStripMenuItem.Text = "Yapıştır";
            this.yapıştırToolStripMenuItem.Click += new System.EventHandler(this.yapıştırToolStripMenuItem_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog1_FileOk);
            // 
            // openFileDialog2
            // 
            this.openFileDialog2.FileName = "openFileDialog2";
            // 
            // fontDialog1
            // 
            this.fontDialog1.Apply += new System.EventHandler(this.fontDialog1_Apply);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(0, 64);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(800, 374);
            this.richTextBox1.TabIndex = 1;
            this.richTextBox1.Text = "";
            this.richTextBox1.TextChanged += new System.EventHandler(this.richTextBox1_TextChanged_1);
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.yeniToolStripButton,
            this.açToolStripButton,
            this.kaydetToolStripButton,
            this.yazdırToolStripButton,
            this.toolStripSeparator,
            this.kesToolStripButton,
            this.kopyalaToolStripButton,
            this.yapıştırToolStripButton,
            this.toolStripSeparator1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 30);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(800, 31);
            this.toolStrip1.TabIndex = 2;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // yeniToolStripButton
            // 
            this.yeniToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.yeniToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("yeniToolStripButton.Image")));
            this.yeniToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.yeniToolStripButton.Name = "yeniToolStripButton";
            this.yeniToolStripButton.Size = new System.Drawing.Size(29, 28);
            this.yeniToolStripButton.Text = "Y&eni";
            this.yeniToolStripButton.Click += new System.EventHandler(this.yeniToolStripButton_Click);
            // 
            // açToolStripButton
            // 
            this.açToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.açToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("açToolStripButton.Image")));
            this.açToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.açToolStripButton.Name = "açToolStripButton";
            this.açToolStripButton.Size = new System.Drawing.Size(29, 28);
            this.açToolStripButton.Text = "&Aç";
            this.açToolStripButton.Click += new System.EventHandler(this.açToolStripButton_Click);
            // 
            // kaydetToolStripButton
            // 
            this.kaydetToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.kaydetToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("kaydetToolStripButton.Image")));
            this.kaydetToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.kaydetToolStripButton.Name = "kaydetToolStripButton";
            this.kaydetToolStripButton.Size = new System.Drawing.Size(29, 28);
            this.kaydetToolStripButton.Text = "&Kaydet";
            this.kaydetToolStripButton.Click += new System.EventHandler(this.kaydetToolStripButton_Click);
            // 
            // yazdırToolStripButton
            // 
            this.yazdırToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.yazdırToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("yazdırToolStripButton.Image")));
            this.yazdırToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.yazdırToolStripButton.Name = "yazdırToolStripButton";
            this.yazdırToolStripButton.Size = new System.Drawing.Size(29, 28);
            this.yazdırToolStripButton.Text = "Y&azdır";
            this.yazdırToolStripButton.Click += new System.EventHandler(this.yazdırToolStripButton_Click);
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(6, 31);
            // 
            // kesToolStripButton
            // 
            this.kesToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.kesToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("kesToolStripButton.Image")));
            this.kesToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.kesToolStripButton.Name = "kesToolStripButton";
            this.kesToolStripButton.Size = new System.Drawing.Size(29, 28);
            this.kesToolStripButton.Text = "K&es";
            this.kesToolStripButton.Click += new System.EventHandler(this.kesToolStripButton_Click);
            // 
            // kopyalaToolStripButton
            // 
            this.kopyalaToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.kopyalaToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("kopyalaToolStripButton.Image")));
            this.kopyalaToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.kopyalaToolStripButton.Name = "kopyalaToolStripButton";
            this.kopyalaToolStripButton.Size = new System.Drawing.Size(29, 28);
            this.kopyalaToolStripButton.Text = "K&opyala";
            this.kopyalaToolStripButton.Click += new System.EventHandler(this.kopyalaToolStripButton_Click);
            // 
            // yapıştırToolStripButton
            // 
            this.yapıştırToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.yapıştırToolStripButton.Image = ((System.Drawing.Image)(resources.GetObject("yapıştırToolStripButton.Image")));
            this.yapıştırToolStripButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.yapıştırToolStripButton.Name = "yapıştırToolStripButton";
            this.yapıştırToolStripButton.Size = new System.Drawing.Size(29, 28);
            this.yapıştırToolStripButton.Text = "&Yapıştır";
            this.yapıştırToolStripButton.Click += new System.EventHandler(this.yapıştırToolStripButton_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 31);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kesToolStripMenuItem1,
            this.kopyalaToolStripMenuItem1,
            this.yapıştırToolStripMenuItem1});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(131, 76);
            // 
            // kesToolStripMenuItem1
            // 
            this.kesToolStripMenuItem1.Name = "kesToolStripMenuItem1";
            this.kesToolStripMenuItem1.Size = new System.Drawing.Size(130, 24);
            this.kesToolStripMenuItem1.Text = "kes";
            // 
            // kopyalaToolStripMenuItem1
            // 
            this.kopyalaToolStripMenuItem1.Name = "kopyalaToolStripMenuItem1";
            this.kopyalaToolStripMenuItem1.Size = new System.Drawing.Size(130, 24);
            this.kopyalaToolStripMenuItem1.Text = "kopyala";
            // 
            // yapıştırToolStripMenuItem1
            // 
            this.yapıştırToolStripMenuItem1.Name = "yapıştırToolStripMenuItem1";
            this.yapıştırToolStripMenuItem1.Size = new System.Drawing.Size(130, 24);
            this.yapıştırToolStripMenuItem1.Text = "yapıştır";
            // 
            // yeniCProjesiToolStripMenuItem
            // 
            this.yeniCProjesiToolStripMenuItem.Name = "yeniCProjesiToolStripMenuItem";
            this.yeniCProjesiToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.yeniCProjesiToolStripMenuItem.Text = "Yeni  C Projesi";
            this.yeniCProjesiToolStripMenuItem.Click += new System.EventHandler(this.yeniCProjesiToolStripMenuItem_Click);
            // 
            // yeniCProjesiToolStripMenuItem1
            // 
            this.yeniCProjesiToolStripMenuItem1.Name = "yeniCProjesiToolStripMenuItem1";
            this.yeniCProjesiToolStripMenuItem1.Size = new System.Drawing.Size(224, 26);
            this.yeniCProjesiToolStripMenuItem1.Text = "Yeni  C++ Projesi";
            this.yeniCProjesiToolStripMenuItem1.Click += new System.EventHandler(this.yeniCProjesiToolStripMenuItem1_Click);
            // 
            // yeniCProjesiToolStripMenuItem2
            // 
            this.yeniCProjesiToolStripMenuItem2.Name = "yeniCProjesiToolStripMenuItem2";
            this.yeniCProjesiToolStripMenuItem2.Size = new System.Drawing.Size(224, 26);
            this.yeniCProjesiToolStripMenuItem2.Text = "Yeni  C# Projesi";
            this.yeniCProjesiToolStripMenuItem2.Click += new System.EventHandler(this.yeniCProjesiToolStripMenuItem2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem dosyaToolStripMenuItem;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog2;
        private System.Windows.Forms.ToolStripMenuItem yeniToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dosyaAçToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dosyaKaydetToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem çıkışToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem biçimToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem yazıTipiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem renkToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem yazıRengiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem zeminRengiToolStripMenuItem;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.ToolStripMenuItem ayarlarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kopyalaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem yapıştırToolStripMenuItem;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton yeniToolStripButton;
        private System.Windows.Forms.ToolStripButton açToolStripButton;
        private System.Windows.Forms.ToolStripButton kaydetToolStripButton;
        private System.Windows.Forms.ToolStripButton yazdırToolStripButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        private System.Windows.Forms.ToolStripButton kesToolStripButton;
        private System.Windows.Forms.ToolStripButton kopyalaToolStripButton;
        private System.Windows.Forms.ToolStripButton yapıştırToolStripButton;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Drawing.Printing.PrintDocument printDocument1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem kesToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem kopyalaToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem yapıştırToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem yeniCProjesiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem yeniCProjesiToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem yeniCProjesiToolStripMenuItem2;
    }
}

