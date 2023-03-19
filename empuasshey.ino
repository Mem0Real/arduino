#include <Servo.h>
#include <PID_v1.h>

#define PIN_INPUT 9
#define PIN_OUTPUT 5

Servo lid;
Servo plotter;
Servo drag;
Servo tilt;
Servo conveyor;
Servo tip;

int startBtn = A5;
int infraredSensor = 9;

int ir1 = 2;
int griddle = 5;
int pumpPin = 6;
int powerRelay = 7;
// int ir2 = 9;

int dragBtn = A1;
int tipBtn = A2;
int pot = A6;
int controlBtn = A7;

unsigned long int totalTime = 0;
unsigned long int timeTillStart = 0;
unsigned long int timer1 = 0;
unsigned long int bakingTime = 0;
unsigned long int previousBakeTime = 0;
unsigned long int timeTillInfrared = 0;
unsigned long int timeTillInfrared2 = 0;
unsigned long int timer2 = 0;
unsigned long int previousLayTime = 0;

bool firstRun = true;
bool layer = true;
bool moveIn = true;
bool moveOut = true;
bool dragBack = true;
bool dragFront = true;
bool takeoutMan = true;

bool defState = false;
bool start = false;
bool infrared = false;
bool infrared2 = false;
bool ddState = false;
bool tdState = false;
bool tipFrontBtn = false;
bool tipBackBtn = false;
bool dragFrontBtn = false;
bool dragBackBtn = false;
bool layCycle = false;

double Setpoint, Input, Output;
double Kp = 50, Ki = 3, Kd = 1;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

float REV = 0;
int RPM_VALUE;
int PREVIOUS = 0;
int TIME;

