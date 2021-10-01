#define ones_bin_dgt_1 2
#define ones_bin_dgt_2 3
#define ones_bin_dgt_3 4
#define ones_bin_dgt_4 5

#define tens_bin_dgt_1 8
#define tens_bin_dgt_2 9
#define tens_bin_dgt_3 10
#define tens_bin_dgt_4 11
#define anal_pin 0

int counter_ones, counter_tens, anal_data = 0;

void setup();
void loop();
void to_display(int number);
void to_display_2(int number);

void setup()
{
	Serial.begin(9600);
	pinMode(ones_bin_dgt_1, OUTPUT);
	pinMode(ones_bin_dgt_2, OUTPUT);
	pinMode(ones_bin_dgt_3, OUTPUT);
	pinMode(ones_bin_dgt_4, OUTPUT);
	
	pinMode(tens_bin_dgt_1, OUTPUT);
	pinMode(tens_bin_dgt_2, OUTPUT);
	pinMode(tens_bin_dgt_3, OUTPUT);
	pinMode(tens_bin_dgt_4, OUTPUT);
	// delay(1000);
};

void loop()
{
	anal_data = analogRead(anal_pin);
	// Serial.println(anal_data);

	for (int i = 0; i, 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			counter_ones++;
			// Serial.println(counter_ones);
			to_display(counter_ones);
			delay(1000);
		};
		counter_ones = 0;
		to_display(counter_ones);
		Serial.println(counter_ones);

		counter_tens++;
		to_display_2(counter_tens);
		delay(1000);
	};
	counter_tens = 0;
	to_display_2(counter_tens);
	Serial.println(counter_tens);

	delay(1000);
};

void to_display(int number)
{
	switch (number)
	{
	case 1:
		digitalWrite(ones_bin_dgt_1, HIGH);
		digitalWrite(ones_bin_dgt_2, LOW);
		digitalWrite(ones_bin_dgt_3, LOW);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;

	case 2:
		digitalWrite(ones_bin_dgt_1, LOW);
		digitalWrite(ones_bin_dgt_2, HIGH);
		digitalWrite(ones_bin_dgt_3, LOW);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;

	case 3:
		digitalWrite(ones_bin_dgt_1, HIGH);
		digitalWrite(ones_bin_dgt_2, HIGH);
		digitalWrite(ones_bin_dgt_3, LOW);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;

	case 4:
		digitalWrite(ones_bin_dgt_1, LOW);
		digitalWrite(ones_bin_dgt_2, LOW);
		digitalWrite(ones_bin_dgt_3, HIGH);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;

	case 5:
		digitalWrite(ones_bin_dgt_1, HIGH);
		digitalWrite(ones_bin_dgt_2, LOW);
		digitalWrite(ones_bin_dgt_3, HIGH);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;

	case 6:
		digitalWrite(ones_bin_dgt_1, LOW);
		digitalWrite(ones_bin_dgt_2, HIGH);
		digitalWrite(ones_bin_dgt_3, HIGH);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;

	case 7:
		digitalWrite(ones_bin_dgt_1, HIGH);
		digitalWrite(ones_bin_dgt_2, HIGH);
		digitalWrite(ones_bin_dgt_3, HIGH);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;

	case 8:
		digitalWrite(ones_bin_dgt_1, LOW);
		digitalWrite(ones_bin_dgt_2, LOW);
		digitalWrite(ones_bin_dgt_3, LOW);
		digitalWrite(ones_bin_dgt_4, HIGH);
		break;

	case 9:
		digitalWrite(ones_bin_dgt_1, HIGH);
		digitalWrite(ones_bin_dgt_2, LOW);
		digitalWrite(ones_bin_dgt_3, LOW);
		digitalWrite(ones_bin_dgt_4, HIGH);
		break;

	default:
		digitalWrite(ones_bin_dgt_1, LOW);
		digitalWrite(ones_bin_dgt_2, LOW);
		digitalWrite(ones_bin_dgt_3, LOW);
		digitalWrite(ones_bin_dgt_4, LOW);
		break;
	}
};

void to_display_2(int number)
{
	switch (number)
	{
	case 1:
		digitalWrite(tens_bin_dgt_1, HIGH);
		digitalWrite(tens_bin_dgt_2, LOW);
		digitalWrite(tens_bin_dgt_3, LOW);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;

	case 2:
		digitalWrite(tens_bin_dgt_1, LOW);
		digitalWrite(tens_bin_dgt_2, HIGH);
		digitalWrite(tens_bin_dgt_3, LOW);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;

	case 3:
		digitalWrite(tens_bin_dgt_1, HIGH);
		digitalWrite(tens_bin_dgt_2, HIGH);
		digitalWrite(tens_bin_dgt_3, LOW);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;

	case 4:
		digitalWrite(tens_bin_dgt_1, LOW);
		digitalWrite(tens_bin_dgt_2, LOW);
		digitalWrite(tens_bin_dgt_3, HIGH);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;

	case 5:
		digitalWrite(tens_bin_dgt_1, HIGH);
		digitalWrite(tens_bin_dgt_2, LOW);
		digitalWrite(tens_bin_dgt_3, HIGH);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;

	case 6:
		digitalWrite(tens_bin_dgt_1, LOW);
		digitalWrite(tens_bin_dgt_2, HIGH);
		digitalWrite(tens_bin_dgt_3, HIGH);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;

	case 7:
		digitalWrite(tens_bin_dgt_1, HIGH);
		digitalWrite(tens_bin_dgt_2, HIGH);
		digitalWrite(tens_bin_dgt_3, HIGH);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;

	case 8:
		digitalWrite(tens_bin_dgt_1, LOW);
		digitalWrite(tens_bin_dgt_2, LOW);
		digitalWrite(tens_bin_dgt_3, LOW);
		digitalWrite(tens_bin_dgt_4, HIGH);
		break;

	case 9:
		digitalWrite(tens_bin_dgt_1, HIGH);
		digitalWrite(tens_bin_dgt_2, LOW);
		digitalWrite(tens_bin_dgt_3, LOW);
		digitalWrite(tens_bin_dgt_4, HIGH);
		break;

	default:
		digitalWrite(tens_bin_dgt_1, LOW);
		digitalWrite(tens_bin_dgt_2, LOW);
		digitalWrite(tens_bin_dgt_3, LOW);
		digitalWrite(tens_bin_dgt_4, LOW);
		break;
	}
};