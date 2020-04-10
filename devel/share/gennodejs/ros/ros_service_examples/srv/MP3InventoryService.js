// Auto-generated. Do not edit!

// (in-package ros_service_examples.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class MP3InventoryServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.request_string = null;
      this.album = null;
    }
    else {
      if (initObj.hasOwnProperty('request_string')) {
        this.request_string = initObj.request_string
      }
      else {
        this.request_string = '';
      }
      if (initObj.hasOwnProperty('album')) {
        this.album = initObj.album
      }
      else {
        this.album = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MP3InventoryServiceRequest
    // Serialize message field [request_string]
    bufferOffset = _serializer.string(obj.request_string, buffer, bufferOffset);
    // Serialize message field [album]
    bufferOffset = _serializer.string(obj.album, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MP3InventoryServiceRequest
    let len;
    let data = new MP3InventoryServiceRequest(null);
    // Deserialize message field [request_string]
    data.request_string = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [album]
    data.album = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.request_string.length;
    length += object.album.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ros_service_examples/MP3InventoryServiceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '87eaf88ba36e173ed9b494bb014cce04';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string request_string
    string album
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MP3InventoryServiceRequest(null);
    if (msg.request_string !== undefined) {
      resolved.request_string = msg.request_string;
    }
    else {
      resolved.request_string = ''
    }

    if (msg.album !== undefined) {
      resolved.album = msg.album;
    }
    else {
      resolved.album = ''
    }

    return resolved;
    }
};

class MP3InventoryServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.response_string = null;
      this.list_strings = null;
    }
    else {
      if (initObj.hasOwnProperty('response_string')) {
        this.response_string = initObj.response_string
      }
      else {
        this.response_string = '';
      }
      if (initObj.hasOwnProperty('list_strings')) {
        this.list_strings = initObj.list_strings
      }
      else {
        this.list_strings = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MP3InventoryServiceResponse
    // Serialize message field [response_string]
    bufferOffset = _serializer.string(obj.response_string, buffer, bufferOffset);
    // Serialize message field [list_strings]
    bufferOffset = _arraySerializer.string(obj.list_strings, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MP3InventoryServiceResponse
    let len;
    let data = new MP3InventoryServiceResponse(null);
    // Deserialize message field [response_string]
    data.response_string = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [list_strings]
    data.list_strings = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.response_string.length;
    object.list_strings.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ros_service_examples/MP3InventoryServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a8645f6a7a49162153e3d5b400b712ab';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string response_string
    string[] list_strings
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MP3InventoryServiceResponse(null);
    if (msg.response_string !== undefined) {
      resolved.response_string = msg.response_string;
    }
    else {
      resolved.response_string = ''
    }

    if (msg.list_strings !== undefined) {
      resolved.list_strings = msg.list_strings;
    }
    else {
      resolved.list_strings = []
    }

    return resolved;
    }
};

module.exports = {
  Request: MP3InventoryServiceRequest,
  Response: MP3InventoryServiceResponse,
  md5sum() { return '40fcdbb3c6bede328ad95cd4459072c8'; },
  datatype() { return 'ros_service_examples/MP3InventoryService'; }
};
