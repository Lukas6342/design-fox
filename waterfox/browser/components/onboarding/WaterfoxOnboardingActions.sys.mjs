/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


/* This file is not finished at All we need to get rid of more stuff here */
import { WaterfoxBrowserStyle } from "resource:///modules/WaterfoxBrowserStyle.sys.mjs";
import { WaterfoxThemeColors } from "resource:///modules/WaterfoxThemeColors.sys.mjs";

const lazy = {};

ChromeUtils.defineESModuleGetters(lazy, {
  SearchService: "moz-src:///toolkit/components/search/SearchService.sys.mjs",
});

const TREE_TABS_PREF = "browser.tabs.verticalTabs.tree.enabled";
const VERTICAL_TABS_PREF = "sidebar.verticalTabs";
const TABBAR_POSITION_PREF = "browser.tabs.toolbarposition";
const UIDENSITY_PREF = "browser.uidensity";

const UIDENSITY = {
  normal: 0,
  compact: 1,
  touch: 2,
};

const TAB_LOCATIONS = new Set([
  "topabove",
  "topbelow",
  "bottomabove",
  "bottombelow",
]);

function setStyle(style) {
  WaterfoxBrowserStyle.setStyle(style);
}

function setThemeMode(mode) {
  WaterfoxThemeColors.setMode(mode);
}

function setThemeColor(color) {
  WaterfoxThemeColors.setColor(color);
}

function setLayout(layout) {
  switch (layout) {
    case "horizontal":
      Services.prefs.setBoolPref(TREE_TABS_PREF, false);
      Services.prefs.setBoolPref(VERTICAL_TABS_PREF, false);
      break;
    case "vertical":
      Services.prefs.setBoolPref(VERTICAL_TABS_PREF, true);
      Services.prefs.setBoolPref(TREE_TABS_PREF, false);
      break;
    case "tree":
      Services.prefs.setBoolPref(VERTICAL_TABS_PREF, true);
      Services.prefs.setBoolPref(TREE_TABS_PREF, true);
      break;
  }
}

function setTabLocation(location) {
  if (!TAB_LOCATIONS.has(location)) {
    return;
  }
  Services.prefs.setStringPref(TABBAR_POSITION_PREF, location);
}

function setUiDensity(density) {
  if (!(density in UIDENSITY)) {
    return;
  }
  Services.prefs.setIntPref(UIDENSITY_PREF, UIDENSITY[density]);
}

async function setDefaultSearchDuckDuckGo() {
  const engine =
    lazy.SearchService.getEngineById("ddg") ||
    lazy.SearchService.getEngineByName("DuckDuckGo");
  if (!engine || engine.hidden) {
    return;
  }
  await lazy.SearchService.setDefault(
    engine,
    lazy.SearchService.CHANGE_REASON.CONFIG
  );
}

export const WaterfoxOnboardingActions = {
  async handle(data = {}) {
    switch (data.action) {
      case "style":
        setStyle(data.value);
        break;
      case "theme-mode":
        setThemeMode(data.value);
        break;
      case "theme-color":
        setThemeColor(data.value);
        break;
      case "layout":
        setLayout(data.value);
        break;
      case "tab-location":
        setTabLocation(data.value);
        break;
      case "density":
        setUiDensity(data.value);
        break;
      case "search-duckduckgo":
      case "search-qwant":
        await setDefaultSearchDuckDuckGo();
        break;
    }
  },

  setStyle,
  setThemeMode,
  setThemeColor,
  setLayout,
  setTabLocation,
  setUiDensity,
  setDefaultSearchDuckDuckGo,
};
