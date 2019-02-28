procedure InitializeComponent;
    begin
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(9, 12);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(197, 31);
        self.label1.TabIndex := 0;
        self.label1.Text := 'Некорретная запись числа.';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(206, 51);
        self.Controls.Add(self.label1);
        self.FormBorderStyle := System.Windows.Forms.FormBorderStyle.FixedToolWindow;
        self.MaximizeBox := false;
        self.MinimizeBox := false;
        self.Name := 'Form1';
        self.Text := 'Ошибка!';
        self.ResumeLayout(false);
    end;
