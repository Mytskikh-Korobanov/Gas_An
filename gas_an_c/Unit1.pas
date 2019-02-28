Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms, Unit2, Unit3, Unit4;

type
  Form1 = class(Form)
    procedure Form1_Load(sender: Object; e: EventArgs);
    procedure button1_Click(sender: Object; e: EventArgs);
    procedure timer1_Tick(sender: Object; e: EventArgs);
    procedure Load_Start;
    function Ser_Reqest(comand: byte): boolean; // обращение к порту (возвращает данные о корректности запроса)
    procedure button2_Click(sender: Object; e: EventArgs);
    procedure serialPort1_DataReceived(sender: Object; e: IO.Ports.SerialDataReceivedEventArgs);
    procedure textBox2_KeyPress(sender: Object; e: KeyPressEventArgs);
    procedure textBox2_KeyDown(sender: Object; e: KeyEventArgs);
  {$region FormDesigner}
  private
    {$resource Unit1.Form1.resources}
    serialPort1: System.IO.Ports.SerialPort;
    components: System.ComponentModel.IContainer;
    button1: Button;
    button2: Button;
    progressBar1: ProgressBar;
    textBox1: TextBox;
    label1: &Label;
    checkBox1: CheckBox;
    label2: &Label;
    textBox2: TextBox;
    textBox3: TextBox;
    label3: &Label;
    groupBox1: GroupBox;
    groupBox2: GroupBox;
    groupBox3: GroupBox;
    label5: &Label;
    listBox1: ListBox;
    timer1: Timer;
    label4: &Label;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation

const
  time_mes = 7; // время измерения в секундах
  
var
  t: integer; // шаги таймера
  rs: byte; // сигнал определяемого вещества
  r0: byte; // сигнал чистого воздуха
  b: boolean; // переключение режимов измерения (true) и калибровки
  stop: boolean; // остановка ввода символов
  warning: real; // предельный уровень концентрации

procedure Form1.Form1_Load(sender: Object; e: EventArgs);
begin
  ListBox1.SelectedIndex := 0;
  progressBar1.Maximum := time_mes*10;
end;

procedure Form1.Load_Start;
begin
  progressBar1.value := 0;
  t := 0;
  timer1.Enabled := True;
end;

function Form1.Ser_Reqest(comand: byte): boolean;
begin
  SerialPort1.PortName := TextBox3.Text;
  try
    SerialPort1.Open;
    SerialPort1.Write(chr(comand));
    result := true;
  except
    on System.IO.IOException do
    begin
      (new Form2).ShowDialog(self);
      result := false;
    end;
  end;
end;

procedure Form1.button1_Click(sender: Object; e: EventArgs);
begin
  b := False;
  if Ser_Reqest(30) then serialPort1.Close();
  if Ser_Reqest(50) then Load_Start;
end;

procedure Form1.timer1_Tick(sender: Object; e: EventArgs);
begin
  if t < progressBar1.Maximum
    then
    begin
      progressBar1.value := progressBar1.value + 1;
      t := t + 1;
    end
    else
      timer1.Enabled := False;
end;

procedure Form1.button2_Click(sender: Object; e: EventArgs);
var
  p: integer;
  s: string;
  a: real;
  err: integer;
begin
  if r0 = 0
    then (new Form3).ShowDialog(self)
    else
    begin
      b := True;
      s := TextBox2.Text;
      p := pos(',', s);
      if p <> 0 then s[p] := '.';
      val(s, a, err);
      if err <> 0 
        then
        begin
          checkBox1.Checked := False;
          (new Form4).ShowDialog(self);
        end
        else
          warning := a;
      if Ser_Reqest(50) then Load_Start;
    end;
end;

procedure Form1.serialPort1_DataReceived(sender: Object; e: IO.Ports.SerialDataReceivedEventArgs);
var
  x, y: real;
  s: string;
begin
  if b then rs := serialPort1.ReadByte
    else r0 := serialPort1.ReadByte;
  serialPort1.Close;
  if b
    then
    begin
      x := r0/rs;
      case ListBox1.SelectedIndex of
        0: y := 18091*exp(-10.7*x);
        1: y := 3332*exp(-10.2*x);
        2: y := 935.1*exp(-7.53*x);
        3: y := 992.5*exp(-17.5*x);
        4: y := 270.3*exp(-11.5*x);
      end;
      s := FloatToStr(y);
      TextBox1.Text := s;
      if checkBox1.Checked
        then
        begin
          if y >= warning
            then 
            begin 
              if not(Ser_Reqest(40)) then;
            end
            else
            begin
              SerialPort1.Close;
              if not(Ser_Reqest(30)) then;
            end
        end
        else
          if not(Ser_Reqest(30)) then;
      serialPort1.Close;
    end;
end;

procedure Form1.textBox2_KeyPress(sender: Object; e: KeyPressEventArgs);
begin
  if (e.KeyChar = '/') or (e.KeyChar = '?') or (e.KeyChar = 'б') or (e.KeyChar = 'ю') or stop 
    then e.Handled := true;
end;

procedure Form1.textBox2_KeyDown(sender: Object; e: KeyEventArgs);
begin
  stop := false;
  case convert.ToByte(e.KeyCode) of
    48..57, 96..105{для NumPad}, 8{BackSpace}, 
      110, 190, 188, 191 {десятичные разделители}: ;
  else 
    stop := true;
  end;
end;

end.