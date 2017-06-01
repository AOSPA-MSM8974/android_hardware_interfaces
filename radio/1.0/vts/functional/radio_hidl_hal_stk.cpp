/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <radio_hidl_hal_utils.h>

using namespace ::android::hardware::radio::V1_0;

/*
 * Test IRadio.sendEnvelope() for the response returned.
 */
TEST_F(RadioHidlTest, sendEnvelope) {
  int serial = 0;

  // Test with sending empty string
  std::string content = "";

  radio->sendEnvelope(++serial, content);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
    EXPECT_EQ(RadioError::NONE, radioRsp->rspInfo.error);
  }

  // Test with sending random string
  content = "0";

  radio->sendEnvelope(++serial, content);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
    EXPECT_EQ(RadioError::NONE, radioRsp->rspInfo.error);
  }
}

/*
 * Test IRadio.sendTerminalResponseToSim() for the response returned.
 */
TEST_F(RadioHidlTest, sendTerminalResponseToSim) {
  int serial = 0;

  // Test with sending empty string
  std::string commandResponse = "";

  radio->sendTerminalResponseToSim(++serial, commandResponse);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
    EXPECT_EQ(RadioError::NONE, radioRsp->rspInfo.error);
  }

  // Test with sending random string
  commandResponse = "0";

  radio->sendTerminalResponseToSim(++serial, commandResponse);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
    EXPECT_EQ(RadioError::NONE, radioRsp->rspInfo.error);
  }
}

/*
 * Test IRadio.handleStkCallSetupRequestFromSim() for the response returned.
 */
TEST_F(RadioHidlTest, handleStkCallSetupRequestFromSim) {
  int serial = 0;
  bool accept = false;

  radio->handleStkCallSetupRequestFromSim(++serial, accept);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
      ASSERT_TRUE(radioRsp->rspInfo.error == RadioError::NONE ||
                  radioRsp->rspInfo.error == RadioError::SYSTEM_ERR ||
                  radioRsp->rspInfo.error == RadioError::NO_MEMORY ||
                  radioRsp->rspInfo.error == RadioError::MODEM_ERR ||
                  radioRsp->rspInfo.error == RadioError::INVALID_ARGUMENTS ||
                  radioRsp->rspInfo.error == RadioError::INTERNAL_ERR);
  }
}

/*
 * Test IRadio.reportStkServiceIsRunning() for the response returned.
 */
TEST_F(RadioHidlTest, reportStkServiceIsRunning) {
  int serial = 0;

  radio->reportStkServiceIsRunning(++serial);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
    EXPECT_EQ(RadioError::NONE, radioRsp->rspInfo.error);
  }
}

/*
 * Test IRadio.sendEnvelopeWithStatus() for the response returned with empty
 * string.
 */
TEST_F(RadioHidlTest, sendEnvelopeWithStatus) {
  int serial = 0;

  // Test with sending empty string
  std::string contents = "";

  radio->sendEnvelopeWithStatus(++serial, contents);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
    EXPECT_EQ(RadioError::NONE, radioRsp->rspInfo.error);
  }

  // Test with sending random string
  contents = "0";

  radio->sendEnvelopeWithStatus(++serial, contents);

  EXPECT_EQ(std::cv_status::no_timeout, wait());
  EXPECT_EQ(RadioResponseType::SOLICITED, radioRsp->rspInfo.type);
  EXPECT_EQ(serial, radioRsp->rspInfo.serial);

  if (cardStatus.cardState == CardState::ABSENT) {
    ASSERT_FALSE(RadioError::NONE == radioRsp->rspInfo.error);
  }
}
