#ifndef TF_DRIFT_HPP_
#define TF_DRIFT_HPP_

#include <iostream>
#include <random>

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

namespace noiser {
class TfDriftClass {
 public:
  TfDriftClass();

  void drift();

 private:
  tf::TransformBroadcaster br_;
  tf::Transform transform_drifted_;

  std::default_random_engine generator_;

  float noise_x_mean_, noise_y_mean_, noise_z_mean_, noise_yaw_mean_, noise_attitude_mean_;
  float noise_x_stddev_, noise_y_stddev_, noise_z_stddev_, noise_yaw_stddev_, noise_attitude_stddev_;
  ros::Publisher pub_;
  std::string source_frame_;
  std::string target_frame_;

  float tf_rate_;
  float drift_x_ = 0.0, drift_y_ = 0.0, drift_z_ = 0.0;
  float drift_yaw_ = 0.0;
  float x_gt = 0.0, y_gt = 0.0, z_gt = 0.0;
};
}  // namespace noiser
#endif  // TF_DRIFT_HPP_