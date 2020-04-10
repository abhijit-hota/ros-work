
(cl:in-package :asdf)

(defsystem "ros_service_examples-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MP3InventoryService" :depends-on ("_package_MP3InventoryService"))
    (:file "_package_MP3InventoryService" :depends-on ("_package"))
  ))