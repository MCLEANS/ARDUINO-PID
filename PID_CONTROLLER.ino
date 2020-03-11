double Kp;
double Ki;
double Kd;

int sample_period = 100;
unsigned long last_time;
double total_error;
double last_error;

double control_signal;

double actual_ph_value;
double desired_ph_value;


void pid_control(int desired_temperature){
  unsigned long current_time = millis();
  unsigned lond delta_time = curent_time - last_time;

  if(delta_time >= sample_period){
    
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
