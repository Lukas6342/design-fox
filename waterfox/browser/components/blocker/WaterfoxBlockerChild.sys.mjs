/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

export class WaterfoxBlockerChild extends JSWindowActorChild {
  receiveMessage(message) {
    if (message.name === "WaterfoxBlocker:ClearCosmeticSelectors") {
      return { ok: true };
    }
    if (message.name === "WaterfoxBlocker:CollectClassIdSnapshot") {
      return { classes: [], ids: [] };
    }
    if (message.name === "WaterfoxBlocker:ApplyCosmeticSelectors") {
      return { applied: 0, ok: true };
    }
    return undefined;
  }

  handleEvent() {}
}
