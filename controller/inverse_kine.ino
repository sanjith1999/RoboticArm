#include <math.h>
// Coordinate of OC
void findOc(bool case_vert) {
  for (int ii = 0; ii < 3; ii++)
    Oc[ii] = dest[ii];
  if (case_vert)
    Oc[2] += 17.5;
  else
    Oc[0] -= 17.5;
}

// CALCULATING FOUR THREE ANGLES
void determineAngles() {
  float pos_ang[3];

  float l1 = 10.5, l2 = 15.3;
  float Xc = Oc[0], Yc = Oc[1], Zc = Oc[2] - 7;
  float r = sqrt(pow(Xc, 2) + pow(Yc, 2) + pow(Zc, 2));

  pos_ang[0] = atan(Yc / Xc);
  pos_ang[2] = acos((pow(r, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2));
  pos_ang[1] = M_PI/2 - atan(Zc / sqrt(pow(Xc, 2) + pow(Yc, 2))) - atan(l2 * sin(pos_ang[2]) / (l1 + l2 * cos(pos_ang[2])));

  for (int i = 0; i < 3; i++)
    config_inv[i] = angleToDegrees(pos_ang[i]) + ang_offset[i];
}

void inverseCalculation(bool inv_case) {
  findOc(inv_case);
  determineAngles();
  Serial.print("\nCALCULATED: \t");
  configVisualizer(config_inv);
}