#define ONES_BIN_DGT_1 2
#define ONES_BIN_DGT_2 3
#define ONES_BIN_DGT_3 4
#define ONES_BIN_DGT_4 5

#define TENS_BIN_DGT_1 8
#define TENS_BIN_DGT_2 9
#define TENS_BIN_DGT_3 10
#define TENS_BIN_DGT_4 11

#define ANAL_PIN 0
//? giving pin numbers a name

#define DPY_1 1
#define DPY_2 2
#define DPY_3 3
#define DPY_4 4
#define DPY_5 5
#define DPY_6 6
#define DPY_7 7
#define DPY_8 8
#define DPY_9 9
//? number displayed on lcd

#define DPY_SPEED 100
//? controls how long to wait when loop() finishes
//? basically display frame rate

double anal_data;
//? initialization of the analog variable
//? keeps track of the voltage from the potentiometer

void setup();
void loop();
void to_display(long number, int pin_1, int pin_2, int pin_3, int pin_4);
void split_digit(int num, int *tens, int *ones);
//? function initialization

void setup()
{
	Serial.begin(9600); //! idk what this does

	pinMode(ONES_BIN_DGT_1, OUTPUT);
	pinMode(ONES_BIN_DGT_2, OUTPUT);
	pinMode(ONES_BIN_DGT_3, OUTPUT);
	pinMode(ONES_BIN_DGT_4, OUTPUT);

	pinMode(TENS_BIN_DGT_1, OUTPUT);
	pinMode(TENS_BIN_DGT_2, OUTPUT);
	pinMode(TENS_BIN_DGT_3, OUTPUT);
	pinMode(TENS_BIN_DGT_4, OUTPUT);

	pinMode(ANAL_PIN, INPUT);
	// delay(1000);
};
//? tells arduino we will be outputing voltage through digital pins 2,3,4,5,8,9,10,11
//? and recive data from analog pin 0

void loop()
{
	anal_data = analogRead(ANAL_PIN); //? potentiometer range: [0,1023]
	//? reads analog voltage from potentiometer

	double scaled_data = (double)anal_data / 10.23; //TODO: replace number with a defined name
	//? scales the analog voltage values from [0,1023] to [0,100]

	scaled_data = round(scaled_data);
	//? round the scaled value for better accuracy

	if (scaled_data == 100)
	{
		scaled_data = 99;
	}
	//? set max value to be 99
	//? since display can not show integers with more than 2 digits

	int tens_digit, ones_digit;
	split_digit(scaled_data, &tens_digit, &ones_digit);
	Serial.print(tens_digit);
	Serial.println(ones_digit); //! always an even number ??

	to_display(ones_digit, ONES_BIN_DGT_1, ONES_BIN_DGT_2, ONES_BIN_DGT_3, ONES_BIN_DGT_4);
	to_display(tens_digit, TENS_BIN_DGT_1, TENS_BIN_DGT_2, TENS_BIN_DGT_3, TENS_BIN_DGT_4);
	//? display the digits in their respective order



	delay(DPY_SPEED);
};
//? main event loop

void split_digit(int num, int *tens, int *ones)
{
	*ones = num % 10;
	*tens = (num / 10) % 10;
};

void to_display(int num, int pin_1, int pin_2, int pin_3, int pin_4)
{
	switch (num)
	{
	case DPY_1:
		digitalWrite(pin_1, HIGH);
		digitalWrite(pin_2, LOW);
		digitalWrite(pin_3, LOW);
		digitalWrite(pin_4, LOW);
		break;

	case DPY_2:
		digitalWrite(pin_1, LOW);
		digitalWrite(pin_2, HIGH);
		digitalWrite(pin_3, LOW);
		digitalWrite(pin_4, LOW);
		break;

	case DPY_3:
		digitalWrite(pin_1, HIGH);
		digitalWrite(pin_2, HIGH);
		digitalWrite(pin_3, LOW);
		digitalWrite(pin_4, LOW);
		break;

	case DPY_4:
		digitalWrite(pin_1, LOW);
		digitalWrite(pin_2, LOW);
		digitalWrite(pin_3, HIGH);
		digitalWrite(pin_4, LOW);
		break;

	case DPY_5:
		digitalWrite(pin_1, HIGH);
		digitalWrite(pin_2, LOW);
		digitalWrite(pin_3, HIGH);
		digitalWrite(pin_4, LOW);
		break;

	case DPY_6:
		digitalWrite(pin_1, LOW);
		digitalWrite(pin_2, HIGH);
		digitalWrite(pin_3, HIGH);
		digitalWrite(pin_4, LOW);
		break;

	case DPY_7:
		digitalWrite(pin_1, HIGH);
		digitalWrite(pin_2, HIGH);
		digitalWrite(pin_3, HIGH);
		digitalWrite(pin_4, LOW);
		break;

	case DPY_8:
		digitalWrite(pin_1, LOW);
		digitalWrite(pin_2, LOW);
		digitalWrite(pin_3, LOW);
		digitalWrite(pin_4, HIGH);
		break;

	case DPY_9:
		digitalWrite(pin_1, HIGH);
		digitalWrite(pin_2, LOW);
		digitalWrite(pin_3, LOW);
		digitalWrite(pin_4, HIGH);
		break;

	default:
		digitalWrite(pin_1, LOW);
		digitalWrite(pin_2, LOW);
		digitalWrite(pin_3, LOW);
		digitalWrite(pin_4, LOW);
		break;
	}
};
//? converts binary numbers to decimal digits on LCD
//? i feel like this can be done more elegently with binary manipulation