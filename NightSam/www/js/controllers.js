angular.module('starter.controllers', [])

.controller('PartysCtrl', function($scope, Partys) {
  $scope.partys = Partys.all();
  $scope.remobe = function(party) {
    Partys.remove(party);
  };
})

.controller('PartyDetailCtrl', function($scope, $stateParams, Partys) {
  $scope.party = Partys.get($stateParams.partyId)
})

.controller('RechercheCtrl', function($scope) {})

.controller('ProposeCtrl', function($scope) {})

.controller('ChatsCtrl', function($scope, Chats) {
  $scope.chats = Chats.all();
  $scope.remove = function(chat) {
    Chats.remove(chat);
  };
})


.controller('ChatDetailCtrl', function($scope, $stateParams, Chats) {
  $scope.chat = Chats.get($stateParams.chatId);
})

.controller('AccountCtrl', function($scope, Profils) {
  $scope.profil = Profils.get(0);
});
