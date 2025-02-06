int a = D4;
int b = D5;
int c = D6;
int d = D7;
int e = D8;
int f = 3;
int g = 1;


int digit_1 = D0; //1- единицы,..., 4-тысячи
int digit_2 = D1;
int digit_3 = D2;
int digit_4 = D3;

void setup()
{
    //Serial.begin(9600);
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(digit_1, OUTPUT);
    pinMode(digit_2, OUTPUT);
    pinMode(digit_3, OUTPUT);
    pinMode(digit_4, OUTPUT);
    digitalWrite(digit_1, true);
    digitalWrite(digit_2, true);
    digitalWrite(digit_3, true);
    digitalWrite(digit_4, true);
}



void segment_out(int n)
{
    digitalWrite(digit_1, false);
    num_display(n % 10);
    delay(1);
    clearDisplay();
    digitalWrite(digit_1, true);
    if (n > 9)
    {
        digitalWrite(digit_2, false);
        num_display(n % 100 / 10);
        delay(1);
        clearDisplay();
        digitalWrite(digit_2, true);
        if (n > 99)
        {
            digitalWrite(digit_3, false);
            num_display(n % 1000 / 100);
            delay(1);
            clearDisplay();
            digitalWrite(digit_3, true);
            if (n > 999)
            {
                digitalWrite(digit_4, false);
                num_display(n / 1000);
                delay(1);
                clearDisplay();
                digitalWrite(digit_4, true);
            }
        }
    }
}
void num_display(int n)
{
    if (n == 0) display0();
    else if (n == 1) display1();
    else if (n == 2) display2();
    else if (n == 3) display3();
    else if (n == 4) display4();
    else if (n == 5) display5();
    else if (n == 6) display6();
    else if (n == 7) display7();
    else if (n == 8) display8();
    else if (n == 9) display9();

}
//display number 1
void display1(void)
{

    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
}
//display number2
void
display2(void)
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);

    digitalWrite(g, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(d, HIGH);
}

// display number3
void display3(void)
{
    digitalWrite(a, HIGH);

    digitalWrite(b, HIGH);

    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);

    digitalWrite(g, HIGH);
}
// display number4
void display4(void)
{

    digitalWrite(f, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(g, HIGH);

    digitalWrite(c, HIGH);

}
// display number5
void display5(void)

{
    digitalWrite(a, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
}
// display number6
void
display6(void)
{
    digitalWrite(a, HIGH);
    digitalWrite(f, HIGH);

    digitalWrite(g, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);

    digitalWrite(e, HIGH);
}
// display number7
void display7(void)

{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
}

// display number8
void display8(void)
{
    digitalWrite(a, HIGH);

    digitalWrite(b, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(c, HIGH);

    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);

}
void display9(void)

{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(g, HIGH);

    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(f, HIGH);

}
void display0(void)
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);

    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);

    digitalWrite(f, HIGH);
}
void clearDisplay(void)
{
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);

    digitalWrite(g, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);

    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
}

void loop()
{
    for (int i = 0;i < 10000;i++)
    {
        //Serial.println(i);
        for (int b = 0;b < 10;b++)
        {
            segment_out(i);
            delay(1);
        }
    }
}
