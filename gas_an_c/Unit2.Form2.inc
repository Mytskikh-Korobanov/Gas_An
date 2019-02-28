procedure InitializeComponent;
    begin
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(12, 9);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(246, 64);
        self.label1.TabIndex := 0;
        self.label1.Text := 'Неверное имя последовательного порта.';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(270, 57);
        self.Controls.Add(self.label1);
        self.FormBorderStyle := System.Windows.Forms.FormBorderStyle.FixedToolWindow;
        self.MaximizeBox := false;
        self.MinimizeBox := false;
        self.Name := 'Form1';
        self.Text := 'Ошибка!';
        self.ResumeLayout(false);
    end;
