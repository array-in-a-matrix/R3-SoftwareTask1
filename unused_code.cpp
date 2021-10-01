//! removing these from the main file increased
//!  preformance in the tinkercad webapp!
//! random leftover from testing / uneeded code:
/*
* for (int i = 0; i, 9; i++)
* {
* 	for (int j = 0; j < 9; j++)
* 	{
* 		anal_data = analogRead(ANAL_PIN);
* 		// Serial.println(anal_data);
* 		double scaled_data = anal_data / 10.23;
* 		// Serial.println(scaled_data);

* 		counter_ones++;
* 		to_display_1(counter_ones);
* 		delay(400);
* 	};
* 	counter_ones = 0;
* 	to_display_1(counter_ones);

* 	counter_tens++;
* 	to_display_2(counter_tens);
* 	delay(400);
* };
* counter_tens = 0;
* to_display_2(counter_tens);
*/
//? counts from 0 to 99 then loops

/*
 * long dec_to_bin(int decimal)
 * {
 * 	long binary = 0;
 * 	int remainder;
 * 	long f = 1;
 * 	while (decimal != 0)
 * 	{
 * 		remainder = decimal % 2;
 * 		binary = binary + remainder * f;
 * 		f = f * 10;
 * 		decimal = decimal / 2;
 * 	}
 * 	return binary;
 * };
 */
//? converts decimal number to a binary representation