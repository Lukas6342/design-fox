/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef waterfox_blocker_xpcom_h
#define waterfox_blocker_xpcom_h

#include "nsCOMPtr.h"
#include "nsIContentPolicy.h"
#include "nsISupportsImpl.h"
#include "nsIWaterfoxBlocker.h"

extern "C" nsresult waterfox_blocker_xpcom_constructor(REFNSIID aIID,
                                                       void** aResult);

class WaterfoxBlockerRequest final : public nsIWaterfoxBlockerRequest {
 public:
  NS_DECL_THREADSAFE_ISUPPORTS
  NS_DECL_NSIWATERFOXBLOCKERREQUEST

  WaterfoxBlockerRequest() = default;

 private:
  ~WaterfoxBlockerRequest() = default;
};

class WaterfoxBlockerContentPolicy final : public nsIContentPolicy {
 public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPOLICY

  WaterfoxBlockerContentPolicy();

 private:
  ~WaterfoxBlockerContentPolicy();
};

class WaterfoxBlockerXPCOM final : public nsIWaterfoxBlockerEngine {
 public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWATERFOXBLOCKERENGINE

  WaterfoxBlockerXPCOM();

 private:
  ~WaterfoxBlockerXPCOM();
};

#endif  // waterfox_blocker_xpcom_h
