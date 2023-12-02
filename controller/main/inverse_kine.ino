#include <math.h>

// CALCULATING FOUR THREE ANGLES
void determineAngles(bool case_vert) {
  float pos_ang[3];  // STORING FIRST THREE ANGLES IN RADIAN
  pos_ang[0] = atan(dest[1] / dest[0]);

  // CALCULATION OF OC
  for (int ii = 0; ii < 3; ii++)
    Oc[ii] = dest[ii];
  if (case_vert)
    Oc[2] += 17.5;
  else
    Oc[0] -= 17.5*cos(pos_ang[0]), Oc[1] -= 17.5*sin(pos_ang[0]);

  float l1 = 10.5, l2 = 14.8;
  float Xc = Oc[0], Yc = Oc[1], Zc = Oc[2] - 7;
  float r = sqrt(pow(Xc, 2) + pow(Yc, 2) + pow(Zc, 2));

  pos_ang[2] = acos((pow(r, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2));
  pos_ang[1] = M_PI / 2 - atan(Zc / sqrt(pow(Xc, 2) + pow(Yc, 2))) - atan(l2 * sin(pos_ang[2]) / (l1 + l2 * cos(pos_ang[2])));


  config_inv[0] = angleToDegrees(pos_ang[0]);
  config_inv[1] = angleToDegrees(pos_ang[1]);
  config_inv[2] = angleToDegrees(pos_ang[2]);

  if (case_vert) config_inv[3] = 180 - config_inv[1] - config_inv[2], config_inv[4] = 0;
  else config_inv[1]-=37, config_inv[2]-=180, config_inv[3] = 90 - config_inv[1] - config_inv[2], config_inv[4] = 90;
  config_inv[5] = 130;

  // COMPENSATION FOR MOTOR ASSEMBLY
  // config_inv[0] += 90;
  // config_inv[2] += 94;
}

void inverseCalculation(bool inv_case) {
  determineAngles(inv_case);
  Serial.print("\nCALCULATED: \t");
  configVisualizer(config_inv);
}