defmodule HelloPhoenix.Router do
  use HelloPhoenix.Web, :router

  pipeline :api do
    plug :accepts, ["json"]
    plug :fetch_session
    plug :fetch_flash
    plug :protect_from_forgery
  end

  scope "/api/v1.0", HelloPhoenix do
    pipe_through :api
    resources "/subscribers", SubscriberController
    resources "/subs_groups", SubsGroupController
  end
end
