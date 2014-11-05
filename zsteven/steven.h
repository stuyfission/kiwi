task main()
{
    motor[motor1] = 100;
    motor[motor2] = 100;
    waitMsec(2000);
    motor[motor1] = -75;
    motor[motor2] = -75;
    waitMsec(2000);
    motor[motor1] = 50;
    motor[motor2] = 50;
    waitMsec(2000);
}