; Auto-generated. Do not edit!


(cl:in-package ros_service_examples-srv)


;//! \htmlinclude MP3InventoryService-request.msg.html

(cl:defclass <MP3InventoryService-request> (roslisp-msg-protocol:ros-message)
  ((request_string
    :reader request_string
    :initarg :request_string
    :type cl:string
    :initform "")
   (album
    :reader album
    :initarg :album
    :type cl:string
    :initform ""))
)

(cl:defclass MP3InventoryService-request (<MP3InventoryService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MP3InventoryService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MP3InventoryService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_service_examples-srv:<MP3InventoryService-request> is deprecated: use ros_service_examples-srv:MP3InventoryService-request instead.")))

(cl:ensure-generic-function 'request_string-val :lambda-list '(m))
(cl:defmethod request_string-val ((m <MP3InventoryService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_service_examples-srv:request_string-val is deprecated.  Use ros_service_examples-srv:request_string instead.")
  (request_string m))

(cl:ensure-generic-function 'album-val :lambda-list '(m))
(cl:defmethod album-val ((m <MP3InventoryService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_service_examples-srv:album-val is deprecated.  Use ros_service_examples-srv:album instead.")
  (album m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MP3InventoryService-request>) ostream)
  "Serializes a message object of type '<MP3InventoryService-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'request_string))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'request_string))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'album))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'album))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MP3InventoryService-request>) istream)
  "Deserializes a message object of type '<MP3InventoryService-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'request_string) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'request_string) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'album) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'album) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MP3InventoryService-request>)))
  "Returns string type for a service object of type '<MP3InventoryService-request>"
  "ros_service_examples/MP3InventoryServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MP3InventoryService-request)))
  "Returns string type for a service object of type 'MP3InventoryService-request"
  "ros_service_examples/MP3InventoryServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MP3InventoryService-request>)))
  "Returns md5sum for a message object of type '<MP3InventoryService-request>"
  "40fcdbb3c6bede328ad95cd4459072c8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MP3InventoryService-request)))
  "Returns md5sum for a message object of type 'MP3InventoryService-request"
  "40fcdbb3c6bede328ad95cd4459072c8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MP3InventoryService-request>)))
  "Returns full string definition for message of type '<MP3InventoryService-request>"
  (cl:format cl:nil "string request_string~%string album~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MP3InventoryService-request)))
  "Returns full string definition for message of type 'MP3InventoryService-request"
  (cl:format cl:nil "string request_string~%string album~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MP3InventoryService-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'request_string))
     4 (cl:length (cl:slot-value msg 'album))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MP3InventoryService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MP3InventoryService-request
    (cl:cons ':request_string (request_string msg))
    (cl:cons ':album (album msg))
))
;//! \htmlinclude MP3InventoryService-response.msg.html

(cl:defclass <MP3InventoryService-response> (roslisp-msg-protocol:ros-message)
  ((response_string
    :reader response_string
    :initarg :response_string
    :type cl:string
    :initform "")
   (list_strings
    :reader list_strings
    :initarg :list_strings
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass MP3InventoryService-response (<MP3InventoryService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MP3InventoryService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MP3InventoryService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_service_examples-srv:<MP3InventoryService-response> is deprecated: use ros_service_examples-srv:MP3InventoryService-response instead.")))

(cl:ensure-generic-function 'response_string-val :lambda-list '(m))
(cl:defmethod response_string-val ((m <MP3InventoryService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_service_examples-srv:response_string-val is deprecated.  Use ros_service_examples-srv:response_string instead.")
  (response_string m))

(cl:ensure-generic-function 'list_strings-val :lambda-list '(m))
(cl:defmethod list_strings-val ((m <MP3InventoryService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_service_examples-srv:list_strings-val is deprecated.  Use ros_service_examples-srv:list_strings instead.")
  (list_strings m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MP3InventoryService-response>) ostream)
  "Serializes a message object of type '<MP3InventoryService-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'response_string))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'response_string))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'list_strings))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'list_strings))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MP3InventoryService-response>) istream)
  "Deserializes a message object of type '<MP3InventoryService-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'response_string) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'response_string) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'list_strings) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'list_strings)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MP3InventoryService-response>)))
  "Returns string type for a service object of type '<MP3InventoryService-response>"
  "ros_service_examples/MP3InventoryServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MP3InventoryService-response)))
  "Returns string type for a service object of type 'MP3InventoryService-response"
  "ros_service_examples/MP3InventoryServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MP3InventoryService-response>)))
  "Returns md5sum for a message object of type '<MP3InventoryService-response>"
  "40fcdbb3c6bede328ad95cd4459072c8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MP3InventoryService-response)))
  "Returns md5sum for a message object of type 'MP3InventoryService-response"
  "40fcdbb3c6bede328ad95cd4459072c8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MP3InventoryService-response>)))
  "Returns full string definition for message of type '<MP3InventoryService-response>"
  (cl:format cl:nil "string response_string~%string[] list_strings~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MP3InventoryService-response)))
  "Returns full string definition for message of type 'MP3InventoryService-response"
  (cl:format cl:nil "string response_string~%string[] list_strings~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MP3InventoryService-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'response_string))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'list_strings) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MP3InventoryService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MP3InventoryService-response
    (cl:cons ':response_string (response_string msg))
    (cl:cons ':list_strings (list_strings msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MP3InventoryService)))
  'MP3InventoryService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MP3InventoryService)))
  'MP3InventoryService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MP3InventoryService)))
  "Returns string type for a service object of type '<MP3InventoryService>"
  "ros_service_examples/MP3InventoryService")