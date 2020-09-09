/*
 * Copyright (c) 2014 Qualcomm Technologies, Inc.  All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */
/*
 * CwFrame.h
 *
 *  Created on: Jul 14, 2014
 */

#ifndef VNCFRAME_H_
#define VNCFRAME_H_

#include "CwBase.h"
#include "CwNode.h"
/////////////////////////////////////////////////////////////
// TODO
// - malloc the frame data so it's only as long as need be
//

///////////////////////////////////////////////////////////////
// CwFrame encapsulates all 4 "types" of frames
/// Key Concepts;
///    - this class is used to build_up, convey, & unpack an outgoing or incoming frame
/// - a frame is composed of: id, flags, data, data len,  and some inferred types
/// - CwFrame helps its client access those components
///-----------------------------------------------------------
/// Upper Layer User
/// - Receiving Data
///   - getDataLen() will tell you the length of the incoming data
///   - getData(ptr, maxlen) will copy up to maxlen bytes into @ptr
///        - and returns length transferred
///   - isErr(), isExt, or isRtr - return the state of those flags
/// - Transmitting Data
///   - setData and set<flag> calls are providing to build a CwFrame for transmission
//
class CwFrame : public CwNode, public CwBase {
public:
    CwFrame();
    CwFrame(uint32_t frameId);

    CwFrame * clone(int deep =1);

    virtual ~CwFrame();
public:
    //----------------------------------------
    // Upper Level Friendly Routines
    //
    // query/fetch incoming info
    //
    // id fields
    uint32_t getId() {return mId;}  // return Frame mId
    uint32_t getMask() { return mMask; }
    int getType() {return mFrType;}         // CwBase::ID_UNDEF,_ERR,_NORM,_EXT,_FD
    // the data
    int getDataLen() {return mDataLen;}     // get length of data portion of frame
    int getData(uint8_t * pData, int maxlen); // copy out the data portion of frame
    uint64_t getTimestamp() {return mTimestamp;}
    // the interface ("canX")
    int getIface() {return mIfNo;};  // return interface number (e.g 0 for "can0")
    int isIface(int ifNo) {return mIfNo == ifNo;}

    void setData(uint8_t * pData, int len); // sets both data and dataLen
    void setFrameId(uint32_t frameId) {mId = frameId;}
    void setTimestamp(uint64_t timestamp) {mTimestamp = timestamp;}
    void setIface(int ifNo) {mIfNo = ifNo;}

    //---------------------------------------------
    // the primary fields in the packet
protected:
    int mId;
    int mDataLen;
    uint8_t mData[CwBase::MAX_DATA];
    uint64_t mTimestamp;
    int mFrType; // CwBase::ID_UNDEF, _NORM, _EXT, _FD
    // useful adjunct info
    int mIfNo;
    uint32_t mMask;  // mask for id for this frame type (2^11-1 or 2^29-1)

    //---------------------------------------------------------------
    // INTERNAL USE ONLY Follows....
    //---------------------------------------------------------------
    // Lower Level (wire-side) friendly and internally used routines
    //
    // setFrame - will copy in the contents of the Frame
    //    - caller retains ownership and should delete it
public:
    // use the following methods internally and with caution
    //
    // getFrame - return a pointer at linux can_Frame structure,
    //    - CwFrame owns (and will delete) this structure

    int getFrameLen();    // length of completed frame
    uint8_t * getDataPtr() {return mData;}
};

#endif /* VNCFRAME_H_ */
