//--------PID variables--------------------------------------
double Kp = 5;
double Ki = 10;
double Kd = 20;

double sample_period = 200;
unsigned long last_time;
double total_error = 0;
double last_error = 0;
bool error_type = true; //false is negative error true is positive error
double control_signal;
double actual_ph_value = 90;
double desired_ph_value = 16;
double error;
//---------------------------------------------------------------------------

void pid_control() {
  unsigned long current_time = millis();
  unsigned long delta_time = current_time - last_time;

  if (delta_time >= sample_period) {
    error = desired_ph_value - actual_ph_value;
   // if((error) == 0.00) total_error = 0;
  //  else  total_error += error;
    
    if (total_error >= 255) total_error = 255;
    if (total_error <= 0) total_error = 0;

    //check if error is positive or negative;
    if (error < 0) error_type = false;
    else if (error > 0) error_type = true;
    //-------------------------------------
    double delta_error = error - last_error;
    last_error = error;


    control_signal = (Kp * error) + (Ki * total_error * sample_period) + ((Kd / sample_period) * delta_error);
    if (control_signal >= 255) control_signal = 255;
    if (control_signal <= -255) control_signal = -255;


    last_time = current_time;

  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pid_control();
  Serial.print(error);
  Serial.print(",");
  Serial.print(control_signal);
  Serial.print(",");
  Serial.println(actual_ph_value);

if(error_type == false) if (error < 0) actual_ph_value -= 1;
if(error_type == true) if (error > 0) actual_ph_value += 1;
  if(error == 0) total_error =0;





}
