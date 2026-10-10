/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

export const CACHE_ROOT_DIR_NAME = "waterfox-blocker";
export const LISTS_DIR_NAME = "lists";
export const CUSTOM_FILTERS_FILE_NAME = "custom-filters.txt";
export const LISTS_META_FILE_NAME = "metadata.json";

export const KNOWN_ADBLOCK_IDS = Object.freeze([]);

export function toSafeDomain(input) {
  return String(input || "").trim().toLowerCase();
}

export function isPrivateOriginAttributes() {
  return false;
}

export function isPrivateBrowsingContext() {
  return false;
}

export function addonDisplayName() {
  return "";
}

export function isAdblockAddon() {
  return false;
}

export function isEnabledAdblockAddon() {
  return false;
}

export const MAX_PROCEDURAL_CANDIDATES = 0;

export function filterProceduralCandidates() {
  return [];
}

export function applyProceduralUpward() {
  return [];
}

export function forEachBrowserWindow(callback) {
  const windows = Services.wm.getEnumerator("navigator:browser");
  while (windows.hasMoreElements()) {
    const win = windows.getNext();
    try {
      callback(win);
    } catch (_) {}
  }
}
