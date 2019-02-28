procedure InitializeComponent;
    begin
        self.components := new System.ComponentModel.Container();
        self.serialPort1 := new System.IO.Ports.SerialPort(self.components);
        self.button1 := new System.Windows.Forms.Button();
        self.button2 := new System.Windows.Forms.Button();
        self.progressBar1 := new System.Windows.Forms.ProgressBar();
        self.textBox1 := new System.Windows.Forms.TextBox();
        self.label1 := new System.Windows.Forms.Label();
        self.checkBox1 := new System.Windows.Forms.CheckBox();
        self.label2 := new System.Windows.Forms.Label();
        self.textBox2 := new System.Windows.Forms.TextBox();
        self.textBox3 := new System.Windows.Forms.TextBox();
        self.label3 := new System.Windows.Forms.Label();
        self.groupBox1 := new System.Windows.Forms.GroupBox();
        self.listBox1 := new System.Windows.Forms.ListBox();
        self.groupBox2 := new System.Windows.Forms.GroupBox();
        self.label5 := new System.Windows.Forms.Label();
        self.groupBox3 := new System.Windows.Forms.GroupBox();
        self.label4 := new System.Windows.Forms.Label();
        self.timer1 := new System.Windows.Forms.Timer(self.components);
        self.groupBox1.SuspendLayout();
        self.groupBox2.SuspendLayout();
        self.groupBox3.SuspendLayout();
        self.SuspendLayout();
        // 
        // serialPort1
        // 
        self.serialPort1.DataReceived += serialPort1_DataReceived;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(21, 142);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(103, 23);
        self.button1.TabIndex := 0;
        self.button1.Text := 'Калибровать';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // button2
        // 
        self.button2.Location := new System.Drawing.Point(359, 142);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(103, 23);
        self.button2.TabIndex := 1;
        self.button2.Text := 'Измерить';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // progressBar1
        // 
        self.progressBar1.Location := new System.Drawing.Point(21, 91);
        self.progressBar1.Maximum := 70;
        self.progressBar1.Name := 'progressBar1';
        self.progressBar1.Size := new System.Drawing.Size(438, 24);
        self.progressBar1.TabIndex := 2;
        // 
        // textBox1
        // 
        self.textBox1.Enabled := false;
        self.textBox1.Location := new System.Drawing.Point(308, 45);
        self.textBox1.Name := 'textBox1';
        self.textBox1.Size := new System.Drawing.Size(151, 22);
        self.textBox1.TabIndex := 3;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(21, 45);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(142, 26);
        self.label1.TabIndex := 4;
        self.label1.Text := 'Концентрация, ppm';
        // 
        // checkBox1
        // 
        self.checkBox1.Location := new System.Drawing.Point(20, 34);
        self.checkBox1.Name := 'checkBox1';
        self.checkBox1.Size := new System.Drawing.Size(418, 58);
        self.checkBox1.TabIndex := 5;
        self.checkBox1.Text := 'Включить определение превышения порогового уровня';
        self.checkBox1.UseVisualStyleBackColor := true;
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(20, 95);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(281, 25);
        self.label2.TabIndex := 6;
        self.label2.Text := 'Пороговый уровень концентрации, ppm';
        // 
        // textBox2
        // 
        self.textBox2.Location := new System.Drawing.Point(338, 95);
        self.textBox2.Name := 'textBox2';
        self.textBox2.Size := new System.Drawing.Size(100, 22);
        self.textBox2.TabIndex := 7;
        self.textBox2.Text := '1';
        self.textBox2.KeyDown += textBox2_KeyDown;
        self.textBox2.KeyPress += textBox2_KeyPress;
        // 
        // textBox3
        // 
        self.textBox3.Location := new System.Drawing.Point(359, 42);
        self.textBox3.Name := 'textBox3';
        self.textBox3.Size := new System.Drawing.Size(100, 22);
        self.textBox3.TabIndex := 8;
        self.textBox3.Text := 'COM5';
        // 
        // label3
        // 
        self.label3.Location := new System.Drawing.Point(21, 42);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(236, 23);
        self.label3.TabIndex := 9;
        self.label3.Text := 'Номер последовательного порта';
        // 
        // groupBox1
        // 
        self.groupBox1.Controls.Add(self.listBox1);
        self.groupBox1.Controls.Add(self.groupBox2);
        self.groupBox1.Controls.Add(self.label5);
        self.groupBox1.Controls.Add(self.label3);
        self.groupBox1.Controls.Add(self.textBox3);
        self.groupBox1.Location := new System.Drawing.Point(12, 12);
        self.groupBox1.Name := 'groupBox1';
        self.groupBox1.Size := new System.Drawing.Size(497, 302);
        self.groupBox1.TabIndex := 10;
        self.groupBox1.TabStop := false;
        self.groupBox1.Text := 'Настройки';
        // 
        // listBox1
        // 
        self.listBox1.FormattingEnabled := true;
        self.listBox1.ItemHeight := 16;
        self.listBox1.Items.AddRange(new System.Object[5]('Метан', 'Аммиак', 'Угарный газ', 'Этанол', 'Водород'));
        self.listBox1.Location := new System.Drawing.Point(308, 90);
        self.listBox1.Name := 'listBox1';
        self.listBox1.Size := new System.Drawing.Size(171, 36);
        self.listBox1.TabIndex := 14;
        // 
        // groupBox2
        // 
        self.groupBox2.Controls.Add(self.checkBox1);
        self.groupBox2.Controls.Add(self.textBox2);
        self.groupBox2.Controls.Add(self.label2);
        self.groupBox2.Location := new System.Drawing.Point(21, 147);
        self.groupBox2.Name := 'groupBox2';
        self.groupBox2.Size := new System.Drawing.Size(458, 131);
        self.groupBox2.TabIndex := 10;
        self.groupBox2.TabStop := false;
        self.groupBox2.Text := 'Определение порогового уровня';
        // 
        // label5
        // 
        self.label5.Location := new System.Drawing.Point(21, 90);
        self.label5.Name := 'label5';
        self.label5.Size := new System.Drawing.Size(212, 23);
        self.label5.TabIndex := 13;
        self.label5.Text := 'Выбор исследуемого вещества';
        // 
        // groupBox3
        // 
        self.groupBox3.Controls.Add(self.textBox1);
        self.groupBox3.Controls.Add(self.label1);
        self.groupBox3.Controls.Add(self.button2);
        self.groupBox3.Controls.Add(self.progressBar1);
        self.groupBox3.Controls.Add(self.button1);
        self.groupBox3.Location := new System.Drawing.Point(12, 338);
        self.groupBox3.Name := 'groupBox3';
        self.groupBox3.Size := new System.Drawing.Size(497, 184);
        self.groupBox3.TabIndex := 11;
        self.groupBox3.TabStop := false;
        self.groupBox3.Text := 'Измерение';
        // 
        // label4
        // 
        self.label4.Anchor := (System.Windows.Forms.AnchorStyles((System.Windows.Forms.AnchorStyles.Bottom or System.Windows.Forms.AnchorStyles.Right)));
        self.label4.Font := new System.Drawing.Font('Microsoft Sans Serif', 8, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, (System.Byte(204)));
        self.label4.Location := new System.Drawing.Point(284, 540);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(225, 23);
        self.label4.TabIndex := 12;
        self.label4.Text := '© Мыцких-Коробанов А.Ю., 2018';
        // 
        // timer1
        // 
        self.timer1.Tick += timer1_Tick;
        // 
        // Form1
        // 
        self.AutoScaleMode := System.Windows.Forms.AutoScaleMode.Inherit;
        self.ClientSize := new System.Drawing.Size(525, 572);
        self.Controls.Add(self.label4);
        self.Controls.Add(self.groupBox3);
        self.Controls.Add(self.groupBox1);
        self.FormBorderStyle := System.Windows.Forms.FormBorderStyle.FixedToolWindow;
        self.MaximizeBox := false;
        self.MinimizeBox := false;
        self.Name := 'Form1';
        self.Text := 'Газовый анализатор';
        self.Load += Form1_Load;
        self.groupBox1.ResumeLayout(false);
        self.groupBox1.PerformLayout();
        self.groupBox2.ResumeLayout(false);
        self.groupBox2.PerformLayout();
        self.groupBox3.ResumeLayout(false);
        self.groupBox3.PerformLayout();
        self.ResumeLayout(false);
    end;
