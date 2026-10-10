/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* Waterfox Blocker - Neutralized Stub */
/* Code from Gemini disables the service IDK HOW */

export const MAX_CUSTOM_FILTERS_BYTES = 0;
export const MAX_CUSTOM_FILTER_LINE_LENGTH = 0;
export const normalizeCustomFiltersText = text => text;
export const REPLACE_MAX_INPUT_BYTES = 0;
export const MAX_REPLACE_DIRECTIVES = 0;

export const WaterfoxBlockerService = new Proxy({}, {
  get(target, prop) {
    if (prop === "isEnabled") return () => false;
    if (prop === "QueryInterface") return ChromeUtils.generateQI([]);
    if (prop === "whenEngineReady") return () => Promise.resolve();
    if (prop === "refreshListsAndEngine") return () => Promise.resolve();
    if (prop === "getBlockedCount") return () => 0;
    if (prop === "getHiddenClassIdSelectors") return () => [];
    if (prop === "getCosmeticResources") return () => null;
    if (prop === "shouldBypassBlocking" || prop === "shouldBypassCosmeticFiltering") return () => true;
    if (prop === "wasHostBlockedFor") return () => false;
    return () => {};
  }
});
