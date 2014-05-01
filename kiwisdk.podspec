Pod::Spec.new do |s|
  s.name         = "KiwiSDK"
  s.version      = "0.1.0"
  s.summary      = "iOS library for Kiwi Motino Devices"
  s.homepage     = "http://www.kiwiwearables.com"
  s.author       = { " Kiwi Wearable Technologies Ltd" => "info@kiwiwearables.com" }
  s.platform     = :ios 
  s.source       = { :git => "https://github.com/kiwiwearables/kiwi-motion-pod.git", :tag => "{s.version}" }
  s.source_files =  'KiwiSDK/Headers/*.h'
  s.preserve_paths = 'KiwiSDK/libKiwiSDK.a'
  s.vendored_libraries = 'KiwiSDK/libEstimoteSDK.a'
  s.ios.deployment_target = '7.0'
  s.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'MobileCoreServices', 'CoreLocation'
  s.requires_arc = true
  s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/KiwiSDK"',
                   'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/KiwiSDK"' }
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2014 Kiwi Wearables Ltd.
      LICENSE
  }
end