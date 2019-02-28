procedure InitializeComponent;
    begin
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(12, 9);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(294, 44);
        self.label1.TabIndex := 0;
        self.label1.Text := 'Перед данным действием необходимо осуществить калибровку.';
        // 
        // Form3
        // 
        self.ClientSize := new System.Drawing.Size(291, 54);
        self.Controls.Add(self.label1);
        self.FormBorderStyle := System.Windows.Forms.FormBorderStyle.FixedToolWindow;
        self.MaximizeBox := false;
        self.MinimizeBox := false;
        self.Name := 'Form3';
        self.Text := 'Предупреждение';
        self.ResumeLayout(false);
    end;
