/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  This file contains the remote interface definitions of the QTI DGNSS Correction
  Data framework.

  Copyright (c) 2019 - 2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef QDGNSSREMOTEAPI_H
#define QDGNSSREMOTEAPI_H

#include "IQDgnss.h"

class QDgnssRemoteSource : public IQDgnssSource
{
public:
    /** @brief Create an instance of an IQDgnssSource object.
         An application can create one source at a time. If the
         application switches to another data source, then it has to
         release the old source and create a new source.

        @param dataSource
        Tell the correction data framework who is going to inject the data
        @param dataFormat
        Tell the correction data framework the injected data format
        @param statusCallback
        The correction data framework updates the status to the application
        through this call back function.
        @param userName
        userName is an 8 byte long string which includes '\n',
        The correction data framework only accepts a userName which has
        been predefined in gps.conf

        @return IQDgnssSource pointer if success.
        nullptr if failed, the failure reason will be sent to the caller
        through the statusCallback, please check QDgnssSourceStatus in IQDgnss.h.

    */
    static shared_ptr<QDgnssRemoteSource> createSource(
        QDgnssDataSource dataSource,
        QDgnssInjectDataFormat dataFormat,
        QDgnssSourceStatusCb statusCallback,
        const char* userName);

    /** @brief Unsubscribe the IQDgnssSource object which was returned from
        createSource().
    */
    void unsubscribe();

    /** @brief Inject the raw correction data to the correction data framework.
        The correction data framework will parse the injected buffer into
        QDGNss messages.

        @param buffer
        The raw correction data message buffer
        @param bufferSize
        The buffer size

    */
    void injectCorrectionData(const uint8_t* buffer, uint32_t bufferSize) override;

    /** @brief Default destructor */
    virtual ~QDgnssRemoteSource() {}

protected:
    QDgnssRemoteSource() {}
    QDgnssRemoteSource(const QDgnssRemoteSource& source) = delete;
    QDgnssRemoteSource& operator=(const QDgnssRemoteSource& source) = delete;
};

class QDgnssRemoteListener : public IQDgnssListener
{
public:
    /** @brief The listener application tells the correction data framework that
         it wants to listen to the QDgnss data.
         Whenever the correction data framework receives raw data from
         a source, it will parse the raw data into QDgnssDataType messages and sends
         QDgnss data to the listener.
         An application can only create one listener at a time.

        @param registeredMsgs
        Tell the correction data framework which QDgnss messages the
        listener is interested in listening to.
        The QDgnssMsgMask is defined in IQDgnss.h.
        @param userName
        userName is 8 bytes long string which includes the '\n'.
        The correction data framework only accepts a userName which has
        been predefined in gps.conf

        @return IQDgnssListener pointer if success.
        nullptr if the userName is not accepted by the Correction Data Framework.
    */
    static shared_ptr<QDgnssRemoteListener> createListener(
        QDgnssMsgMask registeredMsgs, const char* userName);

    /** @brief Unsubscribe the IQDgnssListener object which was returned from
        createListener().
    */
    void unsubscribe();

    /** @brief QDgnssRemoteListener object receives QDgnss messages.

        @param dGnssMsg: DGnss message pointer
        The correction data framework sends QDgnss messages to the
        listener. The dGnssMsg is owned by the correction data
        framework. The listener must not use the dGnssMsg after
        onReceiveMsg returns.
        IQDgnssMsg is defined in IQDgnss.h.
    */
    virtual void onReceiveMsg(unique_ptr<IQDgnssMsg>& dGnssMsg) = 0;

    /** @brief Default destructor */
    virtual ~QDgnssRemoteListener() {}

    void reportDataUsage(const SourceDataUsageMsg& sourceDataUsage) override;

protected:
    QDgnssRemoteListener() {}
    QDgnssRemoteListener(const QDgnssRemoteListener& listener) = delete;
    QDgnssRemoteListener& operator=(const QDgnssRemoteListener& listener) = delete;
};

#endif /* QDGNSSREMOTEAPI_H */
