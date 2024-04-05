/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2023-2024 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:1
**				ÖĞRENCİ ADI............:Baran Yeşilyurt     
**				ÖĞRENCİ NUMARASI.......:g231210078
**              DERSİN ALINDIĞI GRUP...:2. öğretim A
****************************************************************************/


using System;
using System.ComponentModel;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        

        public Form1()
        {
            InitializeComponent();
   


        }
      
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            
            string filePath = openFileDialog1.FileName;

            
            if (!System.IO.File.Exists(filePath))
            {
                // Dosya mevcut değilse, bir hata mesajı gösterir.
                // "MessageBox.Show" yöntemi, bir mesaj penceresi açar.
                MessageBox.Show("Dosya bulunamadı: " + filePath, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return; // İşlemi sonlandırır.
            }

           
           
            try
            {
                string fileContent = System.IO.File.ReadAllText(filePath);

                
                // Örnek: Dosya içeriğini bir RichTextBox kontrolüne gösterir.
                richTextBox1.Text = fileContent;
            }
            catch (Exception ex)
            {
                // Dosya açılırken veya okunurken bir hata oluşursa, bir hata mesajı gösterir.
                // "Exception" nesnesi, hata hakkında ayrıntılı bilgi içerir.
                MessageBox.Show("Dosya açılırken hata oluştu: " + ex.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

      
    }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.FormClosing += new FormClosingEventHandler(Form1_FormClosing);

        }

        private void yazıRengiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Kullanıcının yazı rengini değiştirmesi için renk seçiciyi göster
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.ForeColor = colorDialog1.Color;
            }
        }

        private void zeminRengiToolStripMenuItem_Click(object sender, EventArgs e)
        {// Kullanıcının zemin rengini değiştirmesi için renk seçiciyi göster
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.BackColor = colorDialog1.Color;
            }

        }

        private void renkToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void yazıTipiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.Font = fontDialog1.Font;
            }
        }

        private void yeniToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void dosyaAçToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    
                    string text = System.IO.File.ReadAllText(openFileDialog1.FileName);
                    richTextBox1.Text = text;
                }
                catch (Exception ex)
                {
                   
                    MessageBox.Show("Error opening file: " + ex.Message);
                }
            }
        }

        private void dosyaKaydetToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // SaveFileDialog oluşturulması
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Metin Dosyaları|*.txt|Tüm Dosyalar|*.*";

            // Kullanıcının dosya adını ve yolunu seçmesi için dialog kutusunu göster
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    // richTextBox1 içeriğini seçilen dosyaya yaz
                    System.IO.File.WriteAllText(saveFileDialog.FileName, richTextBox1.Text);
                    MessageBox.Show("Dosya başarıyla kaydedildi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                catch (Exception ex)
                {
                    // Hata oluştuğunda hata mesajını göster
                    MessageBox.Show("Dosya kaydedilirken bir hata oluştu: " + ex.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
      
        private void çıkışToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void dosyaToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

       

        private void fontDialog1_Apply(object sender, EventArgs e)
        {

        }

        private void kesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void kopyalaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void yapıştırToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void richTextBox1_TextChanged_1(object sender, EventArgs e)
        {
           
        }

       
        private void yeniToolStripButton_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(richTextBox1.Text) && richTextBox1.Modified)
            {
                // Kullanıcıya değişiklikleri kaydetmek isteyip istemediğini sormak için bir iletişim kutusu göster
                DialogResult result = MessageBox.Show("Değişiklikleri kaydetmek istiyor musunuz?", "Uyarı", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);

                // Eğer kullanıcı "Evet" derse, dosyayı kaydetmeye çalış
                if (result == DialogResult.Yes)
                {
                    dosyaKaydetToolStripMenuItem_Click(sender, e);
                }
                // Eğer kullanıcı "Hayır" derse, sadece yeni bir dosya oluştur
                else if (result == DialogResult.No)
                {
                    richTextBox1.Clear(); // richTextBox1'i temizle
                }
                // Eğer kullanıcı "İptal" derse, işlemi iptal et
                else if (result == DialogResult.Cancel)
                {
                    return;
                }
            }
            else
            {
                richTextBox1.Clear(); // richTextBox1'i temizle
            }
        }

        private void kesToolStripButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Cut();
        }

        private void yapıştırToolStripButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void kopyalaToolStripButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Copy();
        }

        private void yazdırToolStripButton_Click(object sender, EventArgs e)
        {
            PrintDialog printDialog = new PrintDialog();
            printDialog.Document = printDocument1;
            if (printDialog.ShowDialog() == DialogResult.OK)
            {
                printDocument1.Print();
            }
        }

        private void kaydetToolStripButton_Click(object sender, EventArgs e)
        {
            kaydetToolStripMenuItem_Click(sender, e);
            
        }

        private void açToolStripButton_Click(object sender, EventArgs e)
        {
            // Dosya açma işlemi için OpenFileDialog oluştur
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    // Seçilen dosyanın içeriğini oku
                    string text = System.IO.File.ReadAllText(openFileDialog1.FileName);
                    richTextBox1.Text = text;
                }
                catch (Exception ex)
                {
                    // Hata oluştuğunda hata mesajını göster
                    MessageBox.Show("Dosya açılırken bir hata oluştu: " + ex.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!string.IsNullOrEmpty(richTextBox1.Text) && richTextBox1.Modified)
            {
                // Kullanıcıya değişiklikleri kaydetmek isteyip istemediğini sormak için bir iletişim kutusu göster
                DialogResult result = MessageBox.Show("Değişiklikleri kaydetmek istiyor musunuz?", "Uyarı", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);

                // Eğer kullanıcı "Evet" derse, dosyayı kaydetmeye çalış
                if (result == DialogResult.Yes)
                {
                    dosyaKaydetToolStripMenuItem_Click(sender, e);
                }
                // Eğer kullanıcı "Hayır" derse, formu kapat
                else if (result == DialogResult.No)
                {
                    // Hiçbir işlem yapmadan formu kapat
                }
                // Eğer kullanıcı "İptal" derse, işlemi iptal et
                else if (result == DialogResult.Cancel)
                {
                    e.Cancel = true;
                }
            }
        }

        private void biçimToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void yeniCProjesiToolStripMenuItem2_Click(object sender, EventArgs e)
        {     // Eğer richTextBox1 boş değilse ve değişiklik yapılmışsa
            if (!string.IsNullOrEmpty(richTextBox1.Text) && richTextBox1.Modified)
            {
                // Kullanıcıya değişiklikleri kaydetmek isteyip istemediğini sormak için bir iletişim kutusu göster
                DialogResult saveResult = MessageBox.Show("Değişiklikleri kaydetmek istiyor musunuz?", "Uyarı", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);

                // Eğer kullanıcı "Evet" derse, dosyayı kaydetmeye çalış
                if (saveResult == DialogResult.Yes)
                {
                    // Kullanıcıya dosyayı nereye kaydetmek istediğini sormak için bir SaveFileDialog göster
                    SaveFileDialog saveFileDialog = new SaveFileDialog();
                    saveFileDialog.Filter = "C# Dosyaları (*.cs)|*.cs|Tüm Dosyalar|*.*";

                    // Kullanıcı dosyayı kaydetmeyi seçerse
                    if (saveFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        try
                        {
                            // richTextBox1 içeriğini seçilen dosyaya yaz
                            System.IO.File.WriteAllText(saveFileDialog.FileName, richTextBox1.Text);
                            MessageBox.Show("Dosya başarıyla kaydedildi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        }
                        catch (Exception ex)
                        {
                            // Hata oluştuğunda hata mesajını göster
                            MessageBox.Show("Dosya kaydedilirken bir hata oluştu: " + ex.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                }
                // Eğer kullanıcı "İptal" derse, işlemi iptal et
                else if (saveResult == DialogResult.Cancel)
                {
                    return;
                }
            }

            // RichTextBox'ı temizle
            richTextBox1.Clear();

            // C# ile "Hello World" kodunu yaz
            string kod = @"
using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        Console.WriteLine(""Merhaba Dünya!"");
    }
}
";

            // RichTextBox'a kodu yaz
            richTextBox1.Text = kod;

        }

        private void yeniCProjesiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Eğer richTextBox1 boş değilse ve değişiklik yapılmışsa
            if (!string.IsNullOrEmpty(richTextBox1.Text) && richTextBox1.Modified)
            {
                // Kullanıcıya değişiklikleri kaydetmek isteyip istemediğini sormak için bir iletişim kutusu göster
                DialogResult saveResult = MessageBox.Show("Değişiklikleri kaydetmek istiyor musunuz?", "Uyarı", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);

                // Eğer kullanıcı "Evet" derse, dosyayı kaydetmeye çalış
                if (saveResult == DialogResult.Yes)
                {
                    // Kullanıcıya dosyayı nereye kaydetmek istediğini sormak için bir SaveFileDialog göster
                    SaveFileDialog saveFileDialog = new SaveFileDialog();
                    saveFileDialog.Filter = "C Dosyaları (*.c)|*.c|Tüm Dosyalar (*.*)|*.*";

                    // Kullanıcı dosyayı kaydetmeyi seçerse
                    if (saveFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        try
                        {
                            // richTextBox1 içeriğini seçilen dosyaya yaz
                            System.IO.File.WriteAllText(saveFileDialog.FileName, richTextBox1.Text);
                            MessageBox.Show("Dosya başarıyla kaydedildi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        }
                        catch (Exception ex)
                        {
                            // Hata oluştuğunda hata mesajını göster
                            MessageBox.Show("Dosya kaydedilirken bir hata oluştu: " + ex.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                }
                // Eğer kullanıcı "İptal" derse, işlemi iptal et
                else if (saveResult == DialogResult.Cancel)
                {
                    return;
                }
            }

            // C ile "Hello World" kodunu oluştur
            string kod = @"
    #include <stdio.h>

    int main() {
        printf(""Merhaba Dünya!"");
        return 0;
    }
    ";

            // RichTextBox'a C kodunu yazdır
            richTextBox1.Text = kod;

          
        }
        private void kaydetToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Dosya türünü belirlemek için RichTextBox içeriğini kontrol edin.
            string fileExtension = "";
            if (richTextBox1.Text.Contains("#include <iostream>"))
            {
                fileExtension = ".cpp";
            }
            else if (richTextBox1.Text.Contains("using System;"))
            {
                fileExtension = ".cs";
            }
            else
            {
                fileExtension = ".c";
            }

            // SaveFileDialog oluşturun ve filtrelemeyi ayarlayın.
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = string.Format("{0} Dosyaları (*{0})|*{0}|Tüm Dosyalar|*.*", fileExtension);

            // Kullanıcıya dosya adını ve kaydedilecek yeri seçme imkanı sunun.
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    // RichTextBox içeriğini seçilen dosyaya yazın.
                    System.IO.File.WriteAllText(saveFileDialog.FileName, richTextBox1.Text);
                    MessageBox.Show("Dosya başarıyla kaydedildi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                catch (Exception ex)
                {
                    // Hata oluştuğunda hata mesajı gösterin.
                    MessageBox.Show("Dosya kaydedilirken bir hata oluştu: " + ex.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void yeniCProjesiToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            // Eğer richTextBox1 boş değilse ve değişiklik yapılmışsa
            if (!string.IsNullOrEmpty(richTextBox1.Text) && richTextBox1.Modified)
            {
                // Kullanıcıya değişiklikleri kaydetmek isteyip istemediğini sormak için bir iletişim kutusu göster
                DialogResult saveResult = MessageBox.Show("Değişiklikleri kaydetmek istiyor musunuz?", "Uyarı", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);

                // Eğer kullanıcı "Evet" derse, dosyayı kaydetmeye çalış
                if (saveResult == DialogResult.Yes)
                {
                    // Kullanıcıya dosyayı nereye kaydetmek istediğini sormak için bir SaveFileDialog göster
                    SaveFileDialog saveFileDialog = new SaveFileDialog();
                    saveFileDialog.Filter = "C++ Dosyaları (*.cpp)|*.cpp|Tüm Dosyalar|*.*";

                    // Kullanıcı dosyayı kaydetmeyi seçerse
                    if (saveFileDialog.ShowDialog() == DialogResult.OK)
                    {
                        try
                        {
                            // richTextBox1 içeriğini seçilen dosyaya yaz
                            System.IO.File.WriteAllText(saveFileDialog.FileName, richTextBox1.Text);
                            MessageBox.Show("Dosya başarıyla kaydedildi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        }
                        catch (Exception ex)
                        {
                            // Hata oluştuğunda hata mesajını göster
                            MessageBox.Show("Dosya kaydedilirken bir hata oluştu: " + ex.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                }
                // Eğer kullanıcı "İptal" derse, işlemi iptal et
                else if (saveResult == DialogResult.Cancel)
                {
                    return;
                }
            }

            // RichTextBox'ı temizle
            richTextBox1.Clear();

            // C++ ile "Hello World" kodunu oluşturun.
            string kod = @"
#include <iostream>

int main() {
  std::cout << ""Merhaba Dünya!"" << std::endl;
  return 0;
}
";

            // RichTextBox'a kodu yaz
            richTextBox1.Text = kod;
        }
    }
}
