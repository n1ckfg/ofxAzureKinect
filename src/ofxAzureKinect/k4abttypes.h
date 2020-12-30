// https://microsoft.github.io/Azure-Kinect-Body-Tracking/release/1.x.x/k4abttypes_8h_source.html

#ifndef K4ABTTYPES_H
 #define K4ABTTYPES_H
 
 #include <k4a/k4atypes.h>
 
 #ifdef __cplusplus
 extern "C" {
 #endif
 
 K4A_DECLARE_HANDLE(k4abt_tracker_t);
 
 K4A_DECLARE_HANDLE(k4abt_frame_t);
 
 typedef enum
 {
     K4ABT_JOINT_PELVIS = 0,
     K4ABT_JOINT_SPINE_NAVEL,
     K4ABT_JOINT_SPINE_CHEST,
     K4ABT_JOINT_NECK,
     K4ABT_JOINT_CLAVICLE_LEFT,
     K4ABT_JOINT_SHOULDER_LEFT,
     K4ABT_JOINT_ELBOW_LEFT,
     K4ABT_JOINT_WRIST_LEFT,
     K4ABT_JOINT_HAND_LEFT,
     K4ABT_JOINT_HANDTIP_LEFT,
     K4ABT_JOINT_THUMB_LEFT,
     K4ABT_JOINT_CLAVICLE_RIGHT,
     K4ABT_JOINT_SHOULDER_RIGHT,
     K4ABT_JOINT_ELBOW_RIGHT,
     K4ABT_JOINT_WRIST_RIGHT,
     K4ABT_JOINT_HAND_RIGHT,
     K4ABT_JOINT_HANDTIP_RIGHT,
     K4ABT_JOINT_THUMB_RIGHT,
     K4ABT_JOINT_HIP_LEFT,
     K4ABT_JOINT_KNEE_LEFT,
     K4ABT_JOINT_ANKLE_LEFT,
     K4ABT_JOINT_FOOT_LEFT,
     K4ABT_JOINT_HIP_RIGHT,
     K4ABT_JOINT_KNEE_RIGHT,
     K4ABT_JOINT_ANKLE_RIGHT,
     K4ABT_JOINT_FOOT_RIGHT,
     K4ABT_JOINT_HEAD,
     K4ABT_JOINT_NOSE,
     K4ABT_JOINT_EYE_LEFT,
     K4ABT_JOINT_EAR_LEFT,
     K4ABT_JOINT_EYE_RIGHT,
     K4ABT_JOINT_EAR_RIGHT,
     K4ABT_JOINT_COUNT
 } k4abt_joint_id_t;
 
 typedef enum
 {
     K4ABT_SENSOR_ORIENTATION_DEFAULT = 0,        
     K4ABT_SENSOR_ORIENTATION_CLOCKWISE90,        
     K4ABT_SENSOR_ORIENTATION_COUNTERCLOCKWISE90, 
     K4ABT_SENSOR_ORIENTATION_FLIP180,            
 } k4abt_sensor_orientation_t;
 
 typedef enum
 {
     K4ABT_TRACKER_PROCESSING_MODE_GPU = 0, 
     K4ABT_TRACKER_PROCESSING_MODE_CPU,     
 } k4abt_tracker_processing_mode_t;
 
 typedef struct _k4abt_tracker_configuration_t
 {
     k4abt_sensor_orientation_t sensor_orientation;
 
     k4abt_tracker_processing_mode_t processing_mode;
 
     int32_t gpu_device_id;
 } k4abt_tracker_configuration_t;
 
 typedef union
 {
     struct _wxyz
     {
         float w; 
         float x; 
         float y; 
         float z; 
     } wxyz;      
     float v[4];  
 } k4a_quaternion_t;
 
 typedef enum
 {
     K4ABT_JOINT_CONFIDENCE_NONE = 0,          
     K4ABT_JOINT_CONFIDENCE_LOW = 1,           
     K4ABT_JOINT_CONFIDENCE_MEDIUM = 2,        
     K4ABT_JOINT_CONFIDENCE_HIGH = 3,          
     K4ABT_JOINT_CONFIDENCE_LEVELS_COUNT = 4,  
 } k4abt_joint_confidence_level_t;
 
 typedef struct _k4abt_joint_t
 {
     k4a_float3_t     position;    
     k4a_quaternion_t orientation; 
     k4abt_joint_confidence_level_t confidence_level; 
 } k4abt_joint_t;
 
 typedef struct _k4abt_skeleton_t
 {
     k4abt_joint_t joints[K4ABT_JOINT_COUNT]; 
 } k4abt_skeleton_t;
 
 typedef struct _k4abt_body_t
 {
     uint32_t id;                
     k4abt_skeleton_t skeleton;  
 } k4abt_body_t;
 
 #define K4ABT_BODY_INDEX_MAP_BACKGROUND 255
 
 #define K4ABT_INVALID_BODY_ID 0xFFFFFFFF
 
 #define K4ABT_DEFAULT_TRACKER_SMOOTHING_FACTOR 0.0f
 
 static const k4abt_tracker_configuration_t K4ABT_TRACKER_CONFIG_DEFAULT = { K4ABT_SENSOR_ORIENTATION_DEFAULT,  // sensor_orientation
                                                                             K4ABT_TRACKER_PROCESSING_MODE_GPU, // processing_mode
                                                                             0 };                               // gpu_device_id
 
 #ifdef __cplusplus
 }
 #endif
 
 #endif /* K4ABTTYPES_H */

