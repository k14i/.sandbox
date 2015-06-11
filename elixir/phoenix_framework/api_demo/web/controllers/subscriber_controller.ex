defmodule ApiDemo.Api.V1.SubscriberController do
  use ApiDemo.Web, :controller
  alias ApiDemo.Repo
  alias ApiDemo.Subscriber

  plug :action

  def index(conn, _params) do
    subscribers = Repo.all(Subscriber)
    #subscribers = "[]"
    render conn, subscribers: subscribers
  end

end
