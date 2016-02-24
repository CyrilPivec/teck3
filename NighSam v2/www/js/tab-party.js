angular.module('starter')

.controller('PartyCtrl', function($scope, Parties) {
  var ctrl = this;

  ctrl.parties = Parties.all();
  
  ctrl.remove = function(party) {
    Parties.remove(party);
  };
})

.controller('PartyDetailCtrl', function($scope, $stateParams, Parties) {
  $scope.party = Parties.get($stateParams.partyId)
})