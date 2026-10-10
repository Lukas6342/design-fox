/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "WaterfoxBlockerXPCOM.h"
#include "nsError.h"

NS_IMPL_ISUPPORTS(WaterfoxBlockerContentPolicy, nsIContentPolicy)
NS_IMPL_ISUPPORTS(WaterfoxBlockerXPCOM, nsIWaterfoxBlockerEngine)
NS_IMPL_ISUPPORTS(WaterfoxBlockerRequest, nsIWaterfoxBlockerRequest)

// ============================================================================
// WaterfoxBlockerRequest Stub
// ============================================================================

NS_IMETHODIMP WaterfoxBlockerRequest::GetCanMatch(bool* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = false;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetCanBlock(bool* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = false;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetIsPrivate(bool* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = false;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetBrowserId(uint64_t* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = 0;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetNavigationId(uint64_t* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = 0;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetEngineGeneration(uint64_t* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = 0;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetPolicyGeneration(uint64_t* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = 0;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetIsCurrent(bool* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = false;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetUrl(nsACString& aValue) {
  aValue.Truncate();
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetSourceHostname(nsACString& aValue) {
  aValue.Truncate();
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetHostname(nsACString& aValue) {
  aValue.Truncate();
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetRequestType(nsACString& aValue) {
  aValue.Truncate();
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetRequestMethod(nsACString& aValue) {
  aValue.Truncate();
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::GetIsThirdParty(bool* aValue) {
  NS_ENSURE_ARG_POINTER(aValue);
  *aValue = false;
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::CheckRequestDetailed(nsACString& aResultJson) {
  aResultJson.AssignLiteral(
      "{\"matched\":false,\"important\":false,\"redirect\":\"\","
      "\"rewrittenUrl\":\"\",\"exception\":false}");
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::CheckRequestDetailedAsync(
    nsIWaterfoxBlockerClassificationCallback* aCallback) {
  NS_ENSURE_ARG(aCallback);
  aCallback->OnClassified(
      NS_OK,
      nsLiteralCString("{\"matched\":false,\"important\":false,\"redirect\":\"\","
                       "\"rewrittenUrl\":\"\",\"exception\":false}"));
  return NS_OK;
}

NS_IMETHODIMP WaterfoxBlockerRequest::IsCurrentForLoad(nsILoadInfo* aLoadInfo,
                                                      nsIChannel* aChannel,
                                                      bool* aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = false;
  return NS_OK;
}

// ============================================================================
// WaterfoxBlockerContentPolicy Stub (Niemals blockieren)
// ============================================================================

WaterfoxBlockerContentPolicy::WaterfoxBlockerContentPolicy() = default;
WaterfoxBlockerContentPolicy::~WaterfoxBlockerContentPolicy() = default;

NS_IMETHODIMP
WaterfoxBlockerContentPolicy::ShouldLoad(nsIURI* aContentLocation,
                                         nsILoadInfo* aLoadInfo,
                                         int16_t* aDecision) {
  NS_ENSURE_ARG_POINTER(aDecision);
  *aDecision = nsIContentPolicy::ACCEPT;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerContentPolicy::ShouldProcess(nsIURI* aContentLocation,
                                            nsILoadInfo* aLoadInfo,
                                            int16_t* aDecision) {
  NS_ENSURE_ARG_POINTER(aDecision);
  *aDecision = nsIContentPolicy::ACCEPT;
  return NS_OK;
}

// ============================================================================
// WaterfoxBlockerXPCOM Engine Stub
// ============================================================================

WaterfoxBlockerXPCOM::WaterfoxBlockerXPCOM() = default;
WaterfoxBlockerXPCOM::~WaterfoxBlockerXPCOM() = default;

NS_IMETHODIMP
WaterfoxBlockerXPCOM::InitFromLists(const nsTArray<nsCString>& aFilterLists) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::InitFromCache(const nsTArray<uint8_t>& aCacheData) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::CheckRequestDetailed(
    const nsACString& aUrl, const nsACString& aSourceHostname,
    const nsACString& aHostname, const nsACString& aRequestType,
    const nsACString& aRequestMethod, bool aIsThirdParty, nsACString& _retval) {
  _retval.AssignLiteral(
      "{\"matched\":false,\"important\":false,\"redirect\":\"\","
      "\"rewrittenUrl\":\"\",\"exception\":false}");
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::GetCspDirectives(
    const nsACString& aUrl, const nsACString& aSourceHostname,
    const nsACString& aHostname, const nsACString& aRequestType,
    const nsACString& aRequestMethod, bool aIsThirdParty, nsACString& _retval) {
  _retval.Truncate();
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::GetReplaceDirectives(
    const nsACString& aUrl, const nsACString& aSourceHostname,
    const nsACString& aHostname, const nsACString& aRequestType,
    const nsACString& aRequestMethod, bool aIsThirdParty, nsACString& _retval) {
  _retval.Truncate();
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::Serialize(nsTArray<uint8_t>& _retval) {
  _retval.Clear();
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::GetCosmeticResources(const nsACString& aUrl,
                                           nsACString& _retval) {
  _retval.AssignLiteral("{}");
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::GetHiddenClassIdSelectors(
    const nsACString& aClassesJson, const nsACString& aIdsJson,
    const nsACString& aExceptionsJson, nsACString& _retval) {
  _retval.AssignLiteral("[]");
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::UseResources(const nsACString& aResourcesJson) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::Publish(uint64_t* aGeneration) {
  NS_ENSURE_ARG_POINTER(aGeneration);
  *aGeneration = 1;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::Unpublish() {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::GetPublishedGeneration(uint64_t* aGeneration) {
  NS_ENSURE_ARG_POINTER(aGeneration);
  *aGeneration = 1;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::CaptureRequest(
    const nsACString& aUrl, const nsACString& aSourceHostname,
    const nsACString& aHostname, const nsACString& aRequestType,
    const nsACString& aRequestMethod, bool aIsThirdParty, uint32_t aPolicyFlags,
    uint64_t aBrowserId, uint64_t aNavigationId, uint64_t aValidUntil,
    nsIWaterfoxBlockerRequest** aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  RefPtr<WaterfoxBlockerRequest> req = new WaterfoxBlockerRequest();
  req.forget(aResult);
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::CaptureLoad(nsIURI* aUri, nsILoadInfo* aLoadInfo,
                                  nsIChannel* aChannel, uint32_t aPolicyFlags,
                                  uint64_t aBrowserId, uint64_t aNavigationId,
                                  uint64_t aValidUntil,
                                  nsIWaterfoxBlockerRequest** aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  RefPtr<WaterfoxBlockerRequest> req = new WaterfoxBlockerRequest();
  req.forget(aResult);
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::CapturePolicyLoad(
    nsIURI* aUri, nsILoadInfo* aLoadInfo, nsIChannel* aChannel,
    uint32_t aContextFlags, const nsTArray<nsCString>& aBypassHosts,
    const nsTArray<nsCString>& aAllowedDomains, uint64_t aBrowserId,
    uint64_t aNavigationId, uint64_t aValidUntil,
    nsIWaterfoxBlockerRequest** aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  RefPtr<WaterfoxBlockerRequest> req = new WaterfoxBlockerRequest();
  req.forget(aResult);
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::ShouldBypassHost(const nsACString& aHost, bool aIsPrivate,
                                       bool* aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = true;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::SetNetworkBridge(
    nsIContentClassifierAdBlockingBridge* aBridge) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::OwnsNetworkChannel(nsIChannel* aChannel, bool* aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = false;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::ShouldSkipNetworkChannel(nsIChannel* aChannel,
                                               bool* aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = true;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::GetClassifierService(
    nsIContentClassifierService** aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = nullptr;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::SetDomainAllowances(const nsTArray<nsCString>& aSites,
                                          const nsTArray<nsCString>& aDomains) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::RememberTopHost(uint64_t aBrowserId,
                                      const nsACString& aHost) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::GetTopHost(uint64_t aBrowserId, nsACString& aHost) {
  aHost.Truncate();
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::RememberBlockedDocument(uint64_t aBrowserId,
                                              const nsACString& aHost,
                                              const nsACString& aUrl) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::ForgetBlockedDocument(uint64_t aBrowserId) {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::ConsumeBlockedDocument(uint64_t aBrowserId,
                                             const nsACString& aHost,
                                             const nsACString& aUrl,
                                             bool* aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = false;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::HasNavigationBypass(uint64_t aBrowserId, bool aIsPrivate,
                                          bool* aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = true;
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::ClearNavigationState() {
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::CaptureNativeLoad(nsIURI* aUri, nsILoadInfo* aLoadInfo,
                                        nsIChannel* aChannel, uint16_t aPhase,
                                        nsIWaterfoxBlockerRequest** aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  RefPtr<WaterfoxBlockerRequest> req = new WaterfoxBlockerRequest();
  req.forget(aResult);
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::CheckChannel(
    nsIChannel* aChannel, nsIWaterfoxBlockerClassificationCallback* aCallback) {
  NS_ENSURE_ARG(aCallback);
  aCallback->OnClassified(NS_OK, EmptyCString());
  return NS_OK;
}

NS_IMETHODIMP
WaterfoxBlockerXPCOM::InvalidatePolicy() {
  return NS_OK;
}

extern "C" nsresult waterfox_blocker_xpcom_constructor(REFNSIID aIID,
                                                       void** aResult) {
  NS_ENSURE_ARG_POINTER(aResult);
  *aResult = nullptr;
  RefPtr<WaterfoxBlockerXPCOM> blocker = new WaterfoxBlockerXPCOM();
  return blocker->QueryInterface(aIID, aResult);
}
