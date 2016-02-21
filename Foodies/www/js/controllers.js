angular.module('starter.controllers', ['ionic', 'ngCordova'])

//.controller('DashCtrl', function($scope) {})

.controller('DashCtrl', function($scope, $state) {
  $scope.goAround = function (){
    $state.go("tab.dash-around");
  }
  $scope.goList = function(){
    $state.go("tab.dash-list");
  }
})

.controller('PriceCtrl', function($scope){
  $scope.data = { 'price' : '5.0' };
})



.controller('ChatCtrl', function($scope, $stateParams, profils) {
  $scope.cProfil = profils.get($stateParams.profileId);
})

// Gerer mes plats

.controller('GererCtrl', function($scope, $window, $location, plats) {
   $scope.cPlats = plats.all();
    //$scope.goToPlat = function(plat){
      //$location.path("/tab/gerer/"+plat.id);
      //$window.location.reload()

    //}
})

.controller('GererPlatCtrl', function($scope, $stateParams, plats) {
  $scope.cPlats = plats.get({platId: $stateParams.platId});
})

// Proposer un plat

.controller('AccountCtrl', function($scope, $state) {
  $scope.goGerer = function(){
    $state.go("tab.gerer");
  }
})


.controller('MapCtrl', function($scope, $ionicLoading, $compile, $cordovaGeolocation) { // geolaction = service utilisant cordova qui recupere la pos
     
      function initialize() 
      {
        
        var posOptions = {
            enableHighAccuracy: true,
            timeout: 20000,
            maximumAge: 0
        };

        $cordovaGeolocation.getCurrentPosition(posOptions).then(function (position) {
          var Lat  = position.coords.latitude;
          var Long = position.coords.longitude;
             
          var myLatlng = new google.maps.LatLng(Lat, Long);

          var mapOptions = {
            center: myLatlng,
            zoom: 16,
            mapTypeId: google.maps.MapTypeId.ROADMAP
          };

          var map = new google.maps.Map(document.getElementById("map"),
            mapOptions);
        
          
          $scope.map = map;
        
          })
      }

      initialize();     
})



.controller('CompleteCtrl', function($scope, $ionicLoading, $cordovaGeolocation) { 
     
      function initialize() 
      {
        
          var autocompleteOptions = {
            types: ['(cities)'],
            componentRestrictions: {country: 'fr'}

          };

          var input = document.getElementById('where');
          
          var autocomplete = new google.maps.places.Autocomplete(input, autocompleteOptions);

          var place = autocomplete.getPlace();

          // $scope.place = place;
          $scope.auto = autocomplete;
          
          
      }

      initialize();
})
