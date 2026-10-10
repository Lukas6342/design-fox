/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* Waterfox Blocked Page - Dummy Stub */
export function WaterfoxBlockedPage() {}

WaterfoxBlockedPage.prototype = {
  classID: Components.ID("{bdaa96fc-7ba3-4957-b6c3-dc5ab112bcc1}"),
  QueryInterface: ChromeUtils.generateQI(["nsIAboutModule"]),

  getURIFlags() {
    return Ci.nsIAboutModule.HIDE_FROM_ABOUTABOUT;
  },

  newChannel(uri, loadInfo) {
    return Services.io.newChannelFromURIWithLoadInfo(
      Services.io.newURI("about:blank"),
      loadInfo
    );
  },
};
