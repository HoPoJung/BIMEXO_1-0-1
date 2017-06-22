%% parse data

gyro_leftFoot = VarName1;
gyro_rightFoot = VarName2;
gaitTime = VarName3;
waist_angle = VarName4;
waist_gyro = VarName5;
leftGaitEvent = VarName6;
rightGaitEvent = VarName7;
leftHipVelocity = VarName8;
rightHipVelocity = VarName9;
leftKneeVelocity = VarName10;
rightKneeVelocity = VarName11;


figure
plot(gaitTime, -gyro_leftFoot);
title('Left Foot Angular Velocity');

figure
plot(gaitTime, -gyro_rightFoot);
title('Right Foot Angular Velocity');

figure
plot(gaitTime, leftGaitEvent);
hold on;
plot(gaitTime, rightGaitEvent, 'r');
title('Gait Event');
hold off;

figure
plot(gaitTime, waist_angle);
title('Waist Angle');

figure
plot(gaitTime, waist_gyro);
title('Waist Angular Velocity');
