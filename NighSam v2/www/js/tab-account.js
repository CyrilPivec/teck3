angular.module('starter')

.controller('AccountCtrl', function($scope, $ionicHistory, $location, Profiles) {
  var ctrl = this;
  $scope.accountProfile = Profiles.get(0);

  ctrl.logout = function() {
    window.localStorage.clear();
    $ionicHistory.clearCache();
    $ionicHistory.clearHistory();
    $location.path("/login");
  }
});
