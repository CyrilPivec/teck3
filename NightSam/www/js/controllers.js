angular.module('starter.controllers', ['ionic', 'ngCordova', 'starter.services'])

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

.controller('MapCtrl', function($scope, $cordovaGeolocation, $ionicLoading, $compile) {
  function initalize() {

    var posOption = {
      enableHighAccuracy: true,
      timeout: 20000,
      maximumAge: 0
    };

    $cordovaGeolocation.getCurrentPosition(posOption).then(function (position) {
      var Lat = position.coords.latitude;
      var Long = position.coords.longitude;

      var myLatlng = new google.maps.LatLng(Lat, Long);

      var mapOptions = {
        center: myLatlng,
        zoom: 16,
        mapTypeId: google.maps.MapTypeId.ROADMAP
      };

      var map = new google.maps.Map(document.getElementById("map"), mapOptions);

      $scope.map = map;

    })
  }

  initalize();
})


.controller('ChatDetailCtrl', function($scope, $stateParams, Chats) {
  $scope.chat = Chats.get($stateParams.chatId);
})

.controller('AccountCtrl', function($scope, Profils) {
  $scope.profil = Profils.get(0);
});
