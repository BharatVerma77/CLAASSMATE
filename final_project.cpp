#include <Wt/WApplication.h>
#include <Wt/WText.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPushButton.h>
#include <Wt/WLink.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WMenu.h>
#include <Wt/WAnchor.h>
#include <Wt/WBootstrapTheme.h>

class ClassMateApp : public Wt::WApplication {
public:
    ClassMateApp(const Wt::WEnvironment& env);

private:
    void setupUI();
};

ClassMateApp::ClassMateApp(const Wt::WEnvironment& env) : WApplication(env) {
    setTitle("ClassMate Platform");
    useStyleSheet("styles.css");
    setupUI();
}

void ClassMateApp::setupUI() {
    auto container = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
    container->setStyleClass("container");

    // Header
    auto header = container->addWidget(std::make_unique<Wt::WContainerWidget>());
    header->setStyleClass("header");

    auto logo = header->addWidget(std::make_unique<Wt::WText>("CLASSMATE"));
    logo->setStyleClass("logo-text");

    auto nav = header->addWidget(std::make_unique<Wt::WContainerWidget>());
    nav->setStyleClass("nav-buttons");
    nav->addWidget(std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::WLink::InternalPath, "/dashboard"), "Dashboard"))->setStyleClass("nav-button primary-nav");
    nav->addWidget(std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::WLink::InternalPath, "/user-settings"), "User Settings"))->setStyleClass("nav-button primary-nav");
    
    auto logoutButton = nav->addWidget(std::make_unique<Wt::WPushButton>("Logout"));
    logoutButton->setStyleClass("logout-button");
    logoutButton->clicked().connect([]() {
        // Handle logout logic here
    });

    // Main content
    auto main = container->addWidget(std::make_unique<Wt::WContainerWidget>());
    main->addWidget(std::make_unique<Wt::WText>("Welcome to ClassMate"));
    main->setStyleClass("main");

    // Footer
    auto footer = container->addWidget(std::make_unique<Wt::WContainerWidget>());
    footer->setStyleClass("footer");
    footer->addWidget(std::make_unique<Wt::WText>("&copy; 2024 South Software Solutions™ | All rights reserved"));
}

int main(int argc, char **argv) {
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        return std::make_unique<ClassMateApp>(env);
    });
}
