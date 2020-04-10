;; Auto-generated. Do not edit!


(when (boundp 'ros_service_examples::MP3InventoryService)
  (if (not (find-package "ROS_SERVICE_EXAMPLES"))
    (make-package "ROS_SERVICE_EXAMPLES"))
  (shadow 'MP3InventoryService (find-package "ROS_SERVICE_EXAMPLES")))
(unless (find-package "ROS_SERVICE_EXAMPLES::MP3INVENTORYSERVICE")
  (make-package "ROS_SERVICE_EXAMPLES::MP3INVENTORYSERVICE"))
(unless (find-package "ROS_SERVICE_EXAMPLES::MP3INVENTORYSERVICEREQUEST")
  (make-package "ROS_SERVICE_EXAMPLES::MP3INVENTORYSERVICEREQUEST"))
(unless (find-package "ROS_SERVICE_EXAMPLES::MP3INVENTORYSERVICERESPONSE")
  (make-package "ROS_SERVICE_EXAMPLES::MP3INVENTORYSERVICERESPONSE"))

(in-package "ROS")





(defclass ros_service_examples::MP3InventoryServiceRequest
  :super ros::object
  :slots (_request_string _album ))

(defmethod ros_service_examples::MP3InventoryServiceRequest
  (:init
   (&key
    ((:request_string __request_string) "")
    ((:album __album) "")
    )
   (send-super :init)
   (setq _request_string (string __request_string))
   (setq _album (string __album))
   self)
  (:request_string
   (&optional __request_string)
   (if __request_string (setq _request_string __request_string)) _request_string)
  (:album
   (&optional __album)
   (if __album (setq _album __album)) _album)
  (:serialization-length
   ()
   (+
    ;; string _request_string
    4 (length _request_string)
    ;; string _album
    4 (length _album)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _request_string
       (write-long (length _request_string) s) (princ _request_string s)
     ;; string _album
       (write-long (length _album) s) (princ _album s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _request_string
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _request_string (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _album
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _album (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass ros_service_examples::MP3InventoryServiceResponse
  :super ros::object
  :slots (_response_string _list_strings ))

(defmethod ros_service_examples::MP3InventoryServiceResponse
  (:init
   (&key
    ((:response_string __response_string) "")
    ((:list_strings __list_strings) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _response_string (string __response_string))
   (setq _list_strings __list_strings)
   self)
  (:response_string
   (&optional __response_string)
   (if __response_string (setq _response_string __response_string)) _response_string)
  (:list_strings
   (&optional __list_strings)
   (if __list_strings (setq _list_strings __list_strings)) _list_strings)
  (:serialization-length
   ()
   (+
    ;; string _response_string
    4 (length _response_string)
    ;; string[] _list_strings
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _list_strings)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _response_string
       (write-long (length _response_string) s) (princ _response_string s)
     ;; string[] _list_strings
     (write-long (length _list_strings) s)
     (dolist (elem _list_strings)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _response_string
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _response_string (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string[] _list_strings
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _list_strings (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _list_strings i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(defclass ros_service_examples::MP3InventoryService
  :super ros::object
  :slots ())

(setf (get ros_service_examples::MP3InventoryService :md5sum-) "40fcdbb3c6bede328ad95cd4459072c8")
(setf (get ros_service_examples::MP3InventoryService :datatype-) "ros_service_examples/MP3InventoryService")
(setf (get ros_service_examples::MP3InventoryService :request) ros_service_examples::MP3InventoryServiceRequest)
(setf (get ros_service_examples::MP3InventoryService :response) ros_service_examples::MP3InventoryServiceResponse)

(defmethod ros_service_examples::MP3InventoryServiceRequest
  (:response () (instance ros_service_examples::MP3InventoryServiceResponse :init)))

(setf (get ros_service_examples::MP3InventoryServiceRequest :md5sum-) "40fcdbb3c6bede328ad95cd4459072c8")
(setf (get ros_service_examples::MP3InventoryServiceRequest :datatype-) "ros_service_examples/MP3InventoryServiceRequest")
(setf (get ros_service_examples::MP3InventoryServiceRequest :definition-)
      "string request_string
string album
---
string response_string
string[] list_strings
")

(setf (get ros_service_examples::MP3InventoryServiceResponse :md5sum-) "40fcdbb3c6bede328ad95cd4459072c8")
(setf (get ros_service_examples::MP3InventoryServiceResponse :datatype-) "ros_service_examples/MP3InventoryServiceResponse")
(setf (get ros_service_examples::MP3InventoryServiceResponse :definition-)
      "string request_string
string album
---
string response_string
string[] list_strings
")



(provide :ros_service_examples/MP3InventoryService "40fcdbb3c6bede328ad95cd4459072c8")


