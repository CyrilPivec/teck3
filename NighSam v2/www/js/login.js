angular.module('starter')

.controller('LoginCtrl', function($state, $rootScope, $ionicPopup, AuthService, Backand) {
  var ctrl = this;

  var onLogin = function(){
    $rootScope.$broadcast('authorized');
    $state.go('tab.party');
  }

  ctrl.login = function(data) {
    AuthService.login(data.email, data.password, 'nikdev').then(function(resp) {
      
      if (resp) {
        console.log(resp)
        onLogin();
        var user = {
          id: resp["id"],
          email: resp["email"],
          firstname: resp["firstName"],
          lastname: resp["lastName"],
          pro: (resp["is_pro"] ? "true": "false")
        }
        window.localStorage["user"] = JSON.stringify(user);
      } else {
        console.log("Error user")
        var alertPopup = $ionicPopup.alert({
          title: 'Login failed!',
          template: 'Please check your credentials!'
        });
      }
    });
  }
  
})